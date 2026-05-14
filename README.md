# Linked List

A C++ Xcode project that implements both **singly linked lists** and **doubly linked lists** from scratch.

## Overview

This project is a data structures practice project focused on building linked list implementations manually with dynamic memory management in C++.

It includes:

- a **singly linked list** implementation with common list operations
- a **doubly linked list** implementation with forward and backward traversal
- a small **test harness** in `main.cpp` that uses `assert` to validate behavior

## Features

Singly linked list (LinkedList)
The singly linked list supports:

- append and prepend
- indexed access with get
- indexed update with set
- front and back
- size and isEmpty
- contains and count
- remove first occurrence with remove
- remove all occurrences with removeAll
- insert/remove at a specific index
- clear the list
- append/prepend another list
- swap contents with another list
- reverse the list iteratively
- reverse the list recursively
- print in reverse order

Doubly linked list (DoublyLinkedList)
The doubly linked list supports:

- append and prepend
- remove by value
- forward traversal
- backward traversal

## Project goals

This project practices:

- pointer-based data structure design
- dynamic memory management
- copy constructor / assignment operator behavior
- destructor cleanup
- recursive list algorithms
- test-driven validation with assert
  
## Files

main.cpp — runs validation tests for both list implementations
LinkedList.h / LinkedList.cpp — singly linked list implementation
DoublyLinkedList.h / DoublyLinkedList.cpp — doubly linked list implementation

## Example test coverage

main.cpp currently checks behavior such as:

- appending and prepending nodes
- retrieving and updating values
- removing values
- counting duplicates
- clearing the list
- reversing the list in multiple ways
- appending a list to itself without creating an infinite loop
- basic doubly linked list append/prepend/remove behavior
  
## Build and run

- Open the project in Xcode.
- Select the active scheme.
- Build and run the project.
- Check the console output.

### When the tests pass, the program prints:
All tests passed

## Screenshot


![Program Output](<img width="347" height="989" alt="Screenshot 2026-05-13 at 22 24 51" src="https://github.com/user-attachments/assets/f66e942b-5fa0-4560-9ace-c664791f8ba3" />)

## Notes

This project is intended as a foundational C++ data structures exercise 
and emphasizes correctness, memory cleanup, and basic linked list 
operations implemented without using the STL list containers.
