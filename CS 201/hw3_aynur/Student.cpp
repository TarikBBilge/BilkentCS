/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include "Student.h"

Student::Student(int stuId, string fName, string lName) {
    this->stuId = stuId;
    this->fName = fName;
    this->lName = lName;
    courseCount = 0;
    courseHeadPtr = NULL;
}

Student::~Student() {

}

int Student::getStuId() const {
    return stuId;
}

void Student::setStuId(int stuId) {
    Student::stuId = stuId;
}

const string &Student::getFName() const {
    return fName;
}

void Student::setFName(const string &fName) {
    Student::fName = fName;
}

const string &Student::getLName() const {
    return lName;
}

void Student::setLName(const string &lName) {
    Student::lName = lName;
}

Node* Student::getCourseHeadPtr() const {
    return courseHeadPtr;
}

void Student::setCourseHeadPtr(Node* head) {
    courseHeadPtr = head;
}

int Student::getCourseCount() const {
    return courseCount;
}

void Student::setCourseCount(int courseCount) {
    Student::courseCount = courseCount;
}

Student &Student::operator=(const Student &right) {
    if( &right != this ){
        stuId = right.stuId;
        fName = right.fName;
        lName = right.lName;
        courseHeadPtr = right.courseHeadPtr;
        courseCount = right.courseCount;
    }
    return *this;
}