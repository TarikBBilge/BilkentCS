/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include "Node.h"

Node::Node() {
    next = NULL;
}

void Node::setItem(Course& anItem) {
    item = anItem;
}


void Node::setNext(Node* nextNodePtr) {
    next = nextNodePtr;
}

Course Node::getItem() const {
    return item;
}

Node* Node::getNext() const {
    return next;
}

