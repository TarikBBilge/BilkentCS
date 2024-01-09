/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include <iostream>

#ifndef HW3_COURSENODE_H
#define HW3_COURSENODE_H

using namespace std;

class CourseNode {
public:
    int courseId;
    string courseName;
    CourseNode* next;

    CourseNode(int courseId, const string &courseName);

    virtual ~CourseNode();
};


#endif //HW3_COURSENODE_H
