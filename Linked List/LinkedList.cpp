//
//  LinkedList.cpp
//  Linked List
//
//  Created by Marco D’Eusebio on 4/7/26.
//

#include "LinkedList.h"
#include <iostream>

// default constructor
LinkedList::LinkedList() : head(nullptr) { }

// copy constructor
LinkedList::LinkedList(const LinkedList& rhs) : head(nullptr) {
    Node_1* p = rhs.head;
    Node_1* tail = nullptr;

    while (p != nullptr) {
        Node_1* newNode = new Node_1;
        newNode->data = p->data;
        newNode->next = nullptr;
        
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        p = p->next;
    }
}

// destructor
LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node_1* temp = head->next;
        delete head;
        head = temp;
    }
}

// assignment operator
const LinkedList& LinkedList::operator=(const LinkedList& rhs) {
    if (&rhs != this) {
        LinkedList temp(rhs);
        swap(temp);
    }

    return *this;
}

// get value at index
bool LinkedList::get(int i, ItemType& val) const {
    if (i < 0) {
        return false;
    }

    Node_1* p = head;

    for (int count = 0; count < i; count++) {
        if (p == nullptr) {
            return false;
        }

        p = p->next;
    }

    if (p == nullptr) {
        return false;
    }

    val = p->data;
    return true;
}

// set value at index
bool LinkedList::set(int index, const ItemType& val) {
    if (index < 0) {
        return false;
    }

    Node_1* p = head;

    for (int i = 0; i < index; i++) {
        if (p == nullptr) {
            return false;
        }

        p = p->next;
    }

    if (p == nullptr) {
        return false;
    }

    p->data = val;
    return true;
}

// size
int LinkedList::size() const {
    int count = 0;

    for (Node_1* p = head; p != nullptr; p = p->next) {
        count++;
    }

    return count;
}

// is empty
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// clear list
void LinkedList::clear() {
    while (head != nullptr) {
        Node_1* temp = head;
        head = head->next;
        delete temp;
    }
}

// contains value
bool LinkedList::contains(const ItemType& val) const {
    for (Node_1* p = head; p != nullptr; p = p->next) {
        if (p->data == val) {
            return true;
        }
    }

    return false;
}

// count occurrences of value
int LinkedList::count(const ItemType& val) const {
    int total = 0;

    for (Node_1* p = head; p != nullptr; p = p->next) {
        if (p->data == val) {
            total++;
        }
    }

    return total;
}

// get first value
bool LinkedList::front(ItemType& val) const {
    if (head == nullptr) {
        return false;
    }

    val = head->data;
    return true;
}

// get last value
bool LinkedList::back(ItemType& val) const {
    if (head == nullptr) {
        return false;
    }

    Node_1* p = head;

    while (p->next != nullptr) {
        p = p->next;
    }

    val = p->data;
    return true;
}

// remove node at index
void LinkedList::removeNodeAtIdx(int index) {
    if (index < 0 || head == nullptr) {
        return;
    }

    if (index == 0) {
        Node_1* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node_1* p = head;

    for (int i = 0; i < index - 1; i++) {
        if (p->next == nullptr) {
            return;
        }

        p = p->next;
    }

    Node_1* nodeToDelete = p->next;

    if (nodeToDelete == nullptr) {
        return;
    }

    p->next = nodeToDelete->next;
    delete nodeToDelete;
}

// add node at index
void LinkedList::addNodeAtIdx(int index, const ItemType& val) {
    if (index < 0) {
        return;
    }

    Node_1* newNode = new Node_1(val);

    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node_1* p = head;

    for (int i = 0; i < index - 1; i++) {
        if (p == nullptr) {
            delete newNode;
            return;
        }

        p = p->next;
    }

    if (p == nullptr) {
        delete newNode;
        return;
    }

    newNode->next = p->next;
    p->next = newNode;
}

// print list
void LinkedList::printList() const {
    for (Node_1* p = head; p != nullptr; p = p->next) {
        std::cout << p->data;

        if (p->next != nullptr) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;
}

// print reverse without helper function
void LinkedList::printReverse() const {
    LinkedList temp(*this);
    temp.reverseList();
    temp.printList();
}

void LinkedList::recurPrintReverse() const {
    bool firstPrinted = true;
    
    std::function<void(Node_1*)> print = [&](Node_1* p) {
        // Base case:
        // If p is nullptr, we have gone past the end of the list.
        if (p == nullptr) {
            return;
        }
        
        // Recursive case:
        // Move forward first then print recursively.
        print(p->next);
        
        // After the recursive call returns,
        // we are now printing while coming backward.
        if (!firstPrinted) {
            std::cout << " ";
        }
        
        std::cout << p->data;
        
        // After printing the first value, add a single space before
        // printing each remaining subsequent value of the list.
        firstPrinted = false;
    };
    
    // Start the recursive process at the first node.
    print(head);
    
    std::cout << std::endl;
}

// reverse list
void LinkedList::reverseList() {
    Node_1* prev = nullptr;
    Node_1* current = head;

    while (current != nullptr) {
        Node_1* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
}

void LinkedList::altReverseList() {
    Node_1* reversed = nullptr;
    Node_1* current = head;

    while (current != nullptr) {
        Node_1* next = current->next;

        current->next = reversed;
        reversed = current;

        current = next;
    }

    head = reversed;
}

void LinkedList::recurReverseList() {
    // Base case:
    // Empty list or one-node list
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    
    // Save the first node
    Node_1* first = head;
    
    // Move head to the second node
    head = head->next;
    
    // Recursive case:
    // Reverse the smaller list recursively.
    recurReverseList();
    
    // Put the original first node at the end
    first->next->next = first;
    first->next = nullptr;
}

// prepend single value
void LinkedList::prepend(const ItemType& val) {
    Node_1* newNode = new Node_1(val);
    newNode->next = head;
    head = newNode;
}

// append single value
void LinkedList::append(const ItemType& val) {
    Node_1* newNode = new Node_1(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node_1* p = head;

    while (p->next != nullptr) {
        p = p->next;
    }

    p->next = newNode;
}

// prepend list
void LinkedList::prependList(const LinkedList& other) {
    LinkedList temp(other);
    temp.appendList(*this);
    swap(temp);
}

// append list
void LinkedList::appendList(const LinkedList& other) {
    LinkedList copy(other);

    for (Node_1* p = copy.head; p != nullptr; p = p->next) {
        append(p->data);
    }
}

// remove first occurrence of value
void LinkedList::remove(const ItemType& val) {
    if (head == nullptr) {
        return;
    }

    if (head->data == val) {
        Node_1* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node_1* current = head;

    while (current->next != nullptr && current->next->data != val) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node_1* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// remove every occurrence of value
void LinkedList::removeAll(const ItemType& val) {
    while (head != nullptr && head->data == val) {
        Node_1* temp = head;
        head = head->next;
        delete temp;
    }

    Node_1* p = head;

    while (p != nullptr && p->next != nullptr) {
        if (p->next->data == val) {
            Node_1* temp = p->next;
            p->next = p->next->next;
            delete temp;
        } else {
            p = p->next;
        }
    }
}

// swap
void LinkedList::swap(LinkedList& other) {
    Node_1* temp = head;
    head = other.head;
    other.head = temp;
}
