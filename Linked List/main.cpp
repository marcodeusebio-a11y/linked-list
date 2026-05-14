//
//  main.cpp
//  Linked List
//
//  Created by Marco D’Eusebio on 4/25/26.
//

#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include <cassert>
#include <sstream>
#include <iostream>

int main() {
    LinkedList list;
    assert(list.isEmpty());
    list.append("A");
    list.append("B");
    list.append("C");
    assert(list.size() == 3);

    ItemType val;
    assert(list.get(0, val) && val == "A");
    assert(list.get(2, val) && val == "C");
    assert(!list.get(3, val));

    list.set(1, "BB");
    assert(list.get(1, val) && val == "BB");

    list.prepend("Z");
    assert(list.front(val) && val == "Z");
    assert(list.back(val) && val == "C");

    list.remove("BB");
    assert(!list.contains("BB"));
    assert(list.size() == 3);

    list.append("A");
    assert(list.count("A") == 2);
    list.removeAll("A");
    assert(list.count("A") == 0);

    list.clear();
    list.append("1");
    list.append("2");
    list.append("3");

    list.reverseList();
    assert(list.get(0, val) && val == "3");
    assert(list.get(2, val) && val == "1");

    list.recurReverseList();
    assert(list.get(0, val) && val == "1");
    assert(list.get(2, val) && val == "3");

    list.altReverseList();
    assert(list.get(0, val) && val == "3");
    assert(list.get(2, val) && val == "1");

    list.appendList(list); // verify no infinite loop/self-append bug
    assert(list.size() == 6);

    DoublyLinkedList dlist;
    dlist.append("A");
    dlist.append("B");
    dlist.prepend("Z");
    dlist.remove("A");
    dlist.remove("Z");
    dlist.remove("B");
    dlist.append("C");

    std::cout << "All tests passed\n";
    return 0;
}
