/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include <iostream>
#include "Student.h"
using namespace std;

#ifndef HW3_AYNUR_DOUBLYNODE_H
#define HW3_AYNUR_DOUBLYNODE_H

class DoublyNode {
public:
    DoublyNode();
    friend class RegistrationSystem;
    void setItem(Student& anItem);
    void setNext(DoublyNode* nextDoublyNodePtr);
    void setPrev(DoublyNode* prevDoublyNodePtr);

    Student getItem() const;
    DoublyNode* getNext() const;
    DoublyNode* getPrev() const;

private:
    Student       item;
    DoublyNode*   next;   //pointer to next node
    DoublyNode*   prev;   //pointer to previous node
};

#endif //HW3_AYNUR_DOUBLYNODE_H