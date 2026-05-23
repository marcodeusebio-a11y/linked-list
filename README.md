# Linked List Project

A C++ linked list project that implements both a singly linked list and a doubly linked list from scratch.

This project demonstrates dynamic memory management, pointers, node-based data structures, copy constructors, destructors, assignment operators, recursion, list traversal, insertion, deletion, and list reversal.

---

## Supported Features

The `LinkedList` class supports:

- Append values to the end of the list
- Prepend values to the front of the list
- Get a value by index
- Set a value by index
- Check whether the list is empty
- Get the size of the list
- Clear the entire list
- Check whether a value exists in the list
- Count how many times a value appears
- Get the front value
- Get the back value
- Add a node at a specific index
- Remove a node at a specific index
- Remove the first occurrence of a value
- Remove all occurrences of a value
- Print the list
- Print the list in reverse
- Print the list in reverse recursively
- Reverse the list iteratively
- Reverse the list recursively
- Append another list
- Prepend another list
- Swap two lists

The `DoublyLinkedList` class supports:

- Append values to the end of the list
- Prepend values to the front of the list
- Remove a value from the list
- Print the list forward
- Print the list backward
- Track both the head and tail nodes

---

## Project Purpose

The purpose of this project is to practice implementing linked data structures manually in C++.

Instead of using `std::list` or `std::vector`, this project builds linked lists directly using custom node structs and raw pointers. This helps demonstrate how dynamic memory, pointer links, traversal, insertion, deletion, and copy behavior work internally.

This project practices:

- Pointer-based data structure design
- Pointer manipulation
- Dynamic memory allocation and management
- Manual cleanup with destructors
- Copy constructors
- Assignment operators
- The copy-and-swap pattern
- Singly linked list traversal
- Doubly linked list traversal
- Recursive algorithms
- Defensive index checking
- Test-driven validation with assert
  
---

## Technologies Used

- C++
- Standard Library
- Terminal / Command Line

---

## Project Structure
```
LinkedListProject/
├── main.cpp
├── LinkedList.h
├── LinkedList.cpp
├── DoublyLinkedList.h
├── DoublyLinkedList.cpp
└── README.md
```
---

## Main Classes

### ***LinkedList***

The LinkedList class is a singly linked list that stores typedef values.

Each node contains:
```
ItemType data;
Node_1* next;
```
The list stores a pointer to the first node:
```
Node_1* head;
```
Because the list dynamically allocates nodes, it includes:

- A destructor
- A copy constructor
- An assignment operator
- A swap helper function

These functions help prevent memory leaks and make copied lists independent from each other.

### ***DoublyLinkedList***

The DoublyLinkedList class stores typedef values using nodes that point both forward and backward.

Each node contains:
```
ItemType data;
Node_2* next;
Node_2* prev;
```
The list stores:
```
Node_2* head;
Node_2* tail;
```
This allows the list to be printed from front to back or from back to front.

---

## Build and Run

### Xcode build

- Open the project in Xcode.
- Select the active scheme.
- Then build and run the project using Command + B.

### CLS Build

Compile the project with:
```
g++ -std=c++17 main.cpp LinkedList.cpp DoublyLinkedList.cpp -o linked_list_project
```
Then run with:
```
./linked_list_project
```
---

## Built-In Self-Checks

The project includes assertion-based tests in `main.cpp`.

The tests check behavior such as:

- Empty list detection
- Appending values
- Getting values by index
- Setting values by index
- Prepending values
- Getting the front and back values
- Removing values
- Counting duplicate values
- Removing all matching values
- Clearing the list
- Iterative list reversal
- Recursive list reversal
- Alternate reversal implementation
- Self-appending a list safely
- Basic doubly linked list operations

When the tests pass, the program prints:
```
All tests passed
```
---

## Future Improvements

Possible future upgrades include:

- Convert the list into a template class
- Add a tail pointer to the singly linked list for faster appends
- Add insert-before and insert-after functions
- Add sorting functionality
- Add iterator support
- Add move constructor and move assignment operator
- Add more formal unit tests
- Add exception safety improvements
- Add support for additional data types
- Add a menu-driven demo program

---

## Note

This project is intended as a foundational C++ data structures exercise 
and emphasizes correctness, memory cleanup, and basic linked list 
operations implemented without using the STL list containers.

---

## License

This project is open source and available for educational use.

---

## Screenshot

<img width="347" height="989" alt="Screenshot 2026-05-13 at 22 24 51" src="https://github.com/user-attachments/assets/f66e942b-5fa0-4560-9ace-c664791f8ba3" />


