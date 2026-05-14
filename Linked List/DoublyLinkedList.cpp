//
//  DoublyLinkedList.cpp
//  Functions
//
//  Created by Marco D’Eusebio on 4/7/26.
//

#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList()
    : head(nullptr), tail(nullptr) { }

void DoublyLinkedList::append(const ItemType& val) {
    Node_2* newNode = new Node_2(val);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void DoublyLinkedList::prepend(const ItemType& val) {
    Node_2* newNode = new Node_2(val);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void DoublyLinkedList::remove(const ItemType& val) {
    Node_2* current = head;

    while (current != nullptr && current->data != val) {
        current = current->next;
    }

    if (current == nullptr) {
        return;
    }

    if (current == head) {
        head = current->next;
    }

    if (current == tail) {
        tail = current->prev;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
}

void DoublyLinkedList::printForward() {
    Node_2* current = head;

    while (current != nullptr) {
        std::cout << current->data;

        if (current->next != nullptr) {
            std::cout << " ";
        }

        current = current->next;
    }

    std::cout << std::endl;
}

void DoublyLinkedList::printBackward() {
    Node_2* current = tail;

    while (current != nullptr) {
        std::cout << current->data;

        if (current->prev != nullptr) {
            std::cout << " ";
        }

        current = current->prev;
    }

    std::cout << std::endl;
}

DoublyLinkedList::~DoublyLinkedList() {
    Node_2* current = head;

    while (current != nullptr) {
        Node_2* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr;
    tail = nullptr;
}
