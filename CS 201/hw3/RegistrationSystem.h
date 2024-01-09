/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include <iostream>
#include "CourseNode.h"
#include "StudentNode.h"

using namespace std;

#ifndef HW3_REGISTRATIONSYSTEM_H
#define HW3_REGISTRATIONSYSTEM_H


class RegistrationSystem {
public :
    RegistrationSystem();
    ~ RegistrationSystem();
    void addStudent ( const int studentId , const string firstName , const string
    lastName );
    void deleteStudent ( const int studentId );
    void addCourse ( const int studentId , const int courseId , const string
    courseName );
    void withdrawCourse ( const int studentId , const int courseId );
    void cancelCourse ( const int courseId );
    void showStudent ( const int studentId );
    void showCourse ( const int courseId );
    void showAllStudents ();

private:
    StudentNode* findStudent( int id ); //additional function to find student from student nodes
    StudentNode* stuHead;
    int stuCount;
};
#endif //HW3_REGISTRATIONSYSTEM_H