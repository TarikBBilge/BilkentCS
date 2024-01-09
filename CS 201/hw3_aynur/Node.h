/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include <iostream>
#include "Course.h"
using namespace std;

#ifndef HW3_AYNUR_NODE_H
#define HW3_AYNUR_NODE_H

class Node {
public:
    Node();
    friend class DoublyNode;
    friend class RegistrationSystem;
    void setItem(Course& anItem);
    void setNext(Node* nextNodePtr);

    Course getItem() const;
    Node* getNext() const;

private:
    Course  item;
    Node*   next;   //pointer to next node
};

#endif //HW3_AYNUR_NODE_H