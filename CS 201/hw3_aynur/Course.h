/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include <iostream>
using namespace std;

#ifndef HW3_AYNUR_COURSE_H
#define HW3_AYNUR_COURSE_H


class Course {
public:
    Course( int stuId = 0, int courseId = 0, string courseName = "" );
    ~Course();

    int getStuId() const;
    void setStuId(int stuId);

    int getCourId() const;
    void setCourId(int courId);

    const string &getCourName() const;
    void setCourName(const string &courName);

    Course &operator=( Course& );

private:
    int stuId, courId;
    string courName;
};


#endif //HW3_AYNUR_COURSE_H
