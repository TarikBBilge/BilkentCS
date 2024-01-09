/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include "Course.h"

Course::Course(int stuId, int courseId, string courseName) {
    this->stuId = stuId;
    this->courId = courseId;
    this->courName = courseName;
}

Course::~Course() {}

int Course::getStuId() const {
    return stuId;
}

void Course::setStuId(int stuId) {
    Course::stuId = stuId;
}

int Course::getCourId() const {
    return courId;
}

void Course::setCourId(int courId) {
    Course::courId = courId;
}

const string &Course::getCourName() const {
    return courName;
}

void Course::setCourName(const string &courName) {
    Course::courName = courName;
}

Course &Course::operator=(Course &right) {
    if( &right != this ){
        stuId = right.stuId;
        courId = right.courId;
        courName = right.courName;
    }
    return *this;
}
