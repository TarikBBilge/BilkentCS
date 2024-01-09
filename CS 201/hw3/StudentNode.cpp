/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include <iostream>

#include "StudentNode.h"

StudentNode::StudentNode(int stuId, const string &fName, const string &lName){
    this->studentId = stuId;
    this->firstName = fName;
    this->lastName = lName;
    courseHead = NULL;
}

StudentNode::~StudentNode() {
    //Deallocate all course nodes
    CourseNode* current = courseHead;
    while( current != NULL ) {
        CourseNode* next = current->next;
        delete current;
        current = next;
    }
}
