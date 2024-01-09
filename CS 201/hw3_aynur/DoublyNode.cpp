/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include "DoublyNode.h"


DoublyNode::DoublyNode() {
    next = NULL;
    prev = NULL;
}

void DoublyNode::setItem(Student &anItem) {
    item = anItem;
}

void DoublyNode::setNext(DoublyNode* nextDoublyNodePtr) {
    next = nextDoublyNodePtr;
}


void DoublyNode::setPrev(DoublyNode* prevDoublyNodePtr) {
    prev = prevDoublyNodePtr;
}


Student DoublyNode::getItem() const {
    return item;
}

DoublyNode* DoublyNode::getNext() const {
    return next;
}

DoublyNode* DoublyNode::getPrev() const {
    return prev;
}

