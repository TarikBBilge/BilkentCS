/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include <iostream>
#include "CourseNode.h"

#ifndef HW3_STUDENTNODE_H
#define HW3_STUDENTNODE_H

using namespace std;

class StudentNode {
public:
    int studentId;
    string firstName;
    string lastName;
    CourseNode* courseHead;
    StudentNode* prev;
    StudentNode* next;

    StudentNode(int studentId, const string &firstName, const string &lastName);

    virtual ~StudentNode();
};


#endif //HW3_STUDENTNODE_H
