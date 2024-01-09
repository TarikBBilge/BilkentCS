/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include <iostream>
#include "Node.h"
#include "Course.h"
using namespace std;

#ifndef HW3_AYNUR_STUDENT_H
#define HW3_AYNUR_STUDENT_H


class Student{
public:
    Student( int stuId = 0, string fName = "", string lName = "");
    ~Student();

    int getStuId() const;
    void setStuId(int stuId);

    const string &getFName() const;
    void setFName(const string &fName);

    const string &getLName() const;
    void setLName(const string &lName);

    Node* getCourseHeadPtr() const;
    void setCourseHeadPtr(Node* courseHeadPtr);

    int getCourseCount() const;

    void setCourseCount(int courseCount);

    Student &operator=(const Student&);

private:
    int stuId, courseCount;
    string fName, lName;
    Node* courseHeadPtr;
};


#endif //HW3_AYNUR_STUDENT_H
