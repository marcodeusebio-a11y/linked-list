//
//  LinkedList.h
//  Linked List
//
//  Created by Marco D’Eusebio on 4/7/26.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <functional>
        
using ItemType = std::string;
        
struct Node_1 {
    Node_1(const ItemType& value) : data(value), next(nullptr) {}

    ItemType data;
    Node_1* next;
};

class LinkedList {
private:
    Node_1* head;
    
public:
    // default constructor
    LinkedList();
            
    // copy constructor
    LinkedList(const LinkedList& rhs);
            
    // Destroys all the dynamically allocated memory in the list.
    ~LinkedList();
            
    // assignment operator
    const LinkedList& operator=(const LinkedList& rhs);
            
    // Sets val to the value at position i in this LinkedList and returns true.
    // Returns false if there is no element i.
    bool get(int i, ItemType& val) const;

    // Changes the value at the specified index.
    bool set(int index, const ItemType& val);
    
    // Returns the number of items in the LinkedList.
    int size() const;

    // Returns true if the list has no nodes.
    bool isEmpty() const;

    // Removes all nodes from the list.
    void clear();

    // Returns true if val appears in the list.
    bool contains(const ItemType& val) const;

    // Returns the number of times val appears in the list.
    int count(const ItemType& val) const;

    // Gets the first value in the list.
    bool front(ItemType& val) const;

    // Gets the last value in the list.
    bool back(ItemType& val) const;
    
    // Removes a node from the specified index.
    void removeNodeAtIdx(int index);

    // Adds a node at the specified index.
    void addNodeAtIdx(int index, const ItemType& val);
    
    // Prints the LinkedList.
    void printList() const;
    
    // Prints the LinkedList in reverse order.
    void printReverse() const;
    void recurPrintReverse() const;
    
    // Reverses the LinkedList.
    void reverseList();
    void altReverseList();
    void recurReverseList();
            
    // Inserts val at the front of the list.
    void prepend(const ItemType& val);
    
    // Inserts val at the end of the list.
    void append(const ItemType& val);
    
    // Prepends the values of other onto the front of this LinkedList.
    void prependList(const LinkedList& other);
    
    // Appends the values of other onto the end of this LinkedList.
    void appendList(const LinkedList& other);
    
    // Removes the first occurrence of val from the list.
    void remove(const ItemType& val);

    // Removes every occurrence of val from the list.
    void removeAll(const ItemType& val);

    // Exchange the contents of this LinkedList with the other one.
    void swap(LinkedList& other);
};

#endif  // LINKEDLIST_H
