//
//  DoublyLinkedList.h
//  Functions
//
//  Created by Marco D’Eusebio on 4/7/26.
//
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <string>

using ItemType = std::string;

struct Node_2 {
    Node_2(const ItemType& value) : data(value), next(nullptr), prev(nullptr) {}

    ItemType data;
    Node_2* next;
    Node_2* prev;
};

class DoublyLinkedList {

private:
    Node_2* head;
    Node_2* tail;
    
public:
    DoublyLinkedList();
    void append(const ItemType& val);
    void prepend(const ItemType& val);
    void remove(const ItemType& val);
    void printForward();
    void printBackward();
    ~DoublyLinkedList();
};

#endif  // DOUBLYLINKEDLIST_H
