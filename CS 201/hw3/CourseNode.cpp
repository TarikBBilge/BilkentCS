/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include <iostream>

#include "CourseNode.h"

CourseNode::CourseNode(int id, const string &name){
    this->courseId = id;
    this->courseName = name;
}

CourseNode::~CourseNode() {

}
