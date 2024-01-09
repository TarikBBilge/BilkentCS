/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include "RegistrationSystem.h"

RegistrationSystem::RegistrationSystem(){
    stuHead = NULL;
    stuCount = 0;
}

RegistrationSystem::~RegistrationSystem(){
    //deallocate all student nodes
    StudentNode* currStudent = stuHead;
    while( currStudent != NULL ) {
        StudentNode* nextStudent = currStudent->next;
        delete currStudent;
        currStudent = nextStudent;
    }
}

//private function to find a student by its id
StudentNode* RegistrationSystem::findStudent(int id) {
    StudentNode* cur = stuHead;

    while (cur != NULL) {
        if (cur->studentId == id) {
            return cur;
        }
        cur = cur->next;
    }

    return NULL;
}

void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName) {
    if( stuHead == NULL ){  //if it is the first student
        StudentNode *stuToBeAdded = new StudentNode(studentId, firstName, lastName);
        stuHead = stuToBeAdded;
        stuHead->next = NULL;
        cout << "Student " << studentId << " has been added" << endl;
        return;
    }
    if( findStudent( studentId ) == NULL ) {
        StudentNode *stuToBeAdded = new StudentNode(studentId, firstName, lastName);
        if (stuHead == NULL || studentId < stuHead->studentId) {
            stuToBeAdded->next = stuHead;
            stuHead = stuToBeAdded;
            cout << "Student " << studentId << " has been added" << endl;
        } else {
            StudentNode *prev = stuHead;
            StudentNode *current = stuHead->next;

            while (current != NULL && studentId > current->studentId) {
                prev = current;
                current = current->next;
            }

            stuToBeAdded->next = current;
            prev->next = stuToBeAdded;
            cout << "Student " << studentId << " has been added" << endl;
        }
        return;
    }
    cout << "Student " << studentId << " already exists" << endl;
}

void RegistrationSystem::deleteStudent(const int studentId) {
    StudentNode* student = stuHead;
    StudentNode* prev = NULL;

    while ( student != NULL && student->studentId != studentId) {
        prev = student;
        student = student->next;
    }

    if ( student == NULL ) {
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }

    if (prev == NULL) {
        //if the student to be deleted is the first in the list
        stuHead = student->next;
    }
    else {
        prev->next = student->next;
    }

    CourseNode* curCourse = student->courseHead;
    CourseNode* nextCourse = NULL;

    delete student;
    cout << "Student " << studentId << " has been deleted" << endl;

}

void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName){

    //check if the course exist with another name
    StudentNode* curStu = stuHead;
    while (curStu != NULL) {
        CourseNode *curCourse = curStu->courseHead;
        while (curCourse != NULL) {
            if (curCourse->courseId == courseId && curCourse->courseName != courseName) {
                cout << "Course " << courseId << " already exists with another name" << endl;
                return;
            }
            curCourse = curCourse->next;
        }
        curStu = curStu->next;
    }

    StudentNode* student = findStudent(studentId);
    //check if the student exist
    if (student == NULL) {
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }

    //check if the course already exists for the student
    CourseNode* current = student->courseHead;
    while (current != NULL) {
        if (current->courseId == courseId) {
            cout << "Student " << studentId << " is already enrolled in course " << courseId << endl;
            return;
        }
        current = current->next;
    }

    //add the course
    CourseNode* courToBeAdded = new CourseNode(courseId, courseName);

    if( stuHead == NULL ){  //if it is the first course
        student->courseHead = courToBeAdded;
        student->courseHead->next = NULL;
        cout << "Course " << courseId << " has been added to student " << studentId << endl;
        return;
    }

    if (student->courseHead == NULL || courseId < student->courseHead->courseId) {
        courToBeAdded->next = student->courseHead;
        student->courseHead = courToBeAdded;
        cout << "Course " << courseId << " has been added to student " << studentId << endl;
    }
    else {
        CourseNode* prev = student->courseHead;
        CourseNode* current = student->courseHead->next;

        while (current != NULL && courseId > current->courseId) {
            prev = current;
            current = current->next;
        }

        courToBeAdded->next = current;
        prev->next = courToBeAdded;
        cout << "Course " << courseId << " has been added to student " << studentId << endl;
    }
}

void RegistrationSystem::withdrawCourse(const int studentId, const int courseId){
    StudentNode* student = findStudent(studentId);

    if (student == NULL) {
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }

    CourseNode* curCourse = student->courseHead;
    CourseNode* prev = NULL;

    while (curCourse != NULL && curCourse->courseId != courseId) {
        prev = curCourse;
        curCourse = curCourse->next;
    }

    if (curCourse == NULL) {
        cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
        return;
    }

    if (prev == NULL) { // If the course to be withdrawn is the first in the list
        student->courseHead = curCourse->next;
    } else {
        prev->next = curCourse->next;
    }

    delete curCourse; //delete the course
    cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
}

void RegistrationSystem::cancelCourse(const int courseId){
    StudentNode* curStudent = stuHead;
    bool courseExist = false;
    while( curStudent != NULL ){
        CourseNode* curCourse = curStudent->courseHead;
        CourseNode* prevCourse = NULL;

        while (curCourse != NULL && curCourse->courseId != courseId) {
            prevCourse = curCourse;
            curCourse = curCourse->next;
        }

        if (curCourse != NULL) {
            if (prevCourse == NULL) { // If the course to be withdrawn is the first in the list
                curStudent->courseHead = curCourse->next;
            } else {
                prevCourse->next = curCourse->next;
            }
            courseExist = true;
            delete curCourse; //delete the course from the student
        }

        curStudent = curStudent->next;
    }
    if(courseExist){
        cout << "Course " << courseId << " has been cancelled" << endl;
        return;
    }
    cout << "Course " << courseId << " does not exist" << endl;
}

void RegistrationSystem::showStudent(const int studentId){
    StudentNode* student = findStudent(studentId);
    if( student == NULL ){
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }
    cout << "Student id First name Last name" << endl;
    cout << student->studentId << " " <<
         student->firstName << " " << student->lastName << endl;
    if( student->courseHead != NULL ){
        cout << "Course id Course name" << endl;
        CourseNode* curCourNode = student->courseHead;
        while( curCourNode != NULL ){
            cout << curCourNode->courseId << " " << curCourNode->courseName << endl;
            curCourNode = curCourNode->next;
        }
    }
}

void RegistrationSystem::showCourse(const int courseId){
    StudentNode* curStudent = stuHead;
    bool courseExist = false;
    while( curStudent != NULL ){
        CourseNode* curCourse = curStudent->courseHead;
        while( curCourse != NULL ){
            if( curCourse->courseId == courseId && courseExist == false ){  //write the first student
                cout << "Course id Course name" << endl;
                cout << courseId << " " << curCourse->courseName << endl;

                cout << "Student id First name Last name" << endl;
                cout << curStudent->studentId << " " <<
                     curStudent->firstName << " " << curStudent->lastName << endl;
                courseExist = true;
            }
            else if( curCourse->courseId == courseId && courseExist == true ){
                cout << curStudent->studentId << " " <<
                     curStudent->firstName << " " << curStudent->lastName << endl;
            }
            curCourse = curCourse->next;
        }
        curStudent = curStudent->next;
    }
    if(!courseExist){
        cout << "Course " << courseId << " does not exist" << endl;
    }
}

void RegistrationSystem::showAllStudents(){
    if( stuHead == NULL ){
        cout << "There are no students in the system" << endl;
        return;
    }
    StudentNode* curStuNode = stuHead;
    cout << "Student id First name Last name" << endl;
    while( curStuNode != NULL ){
        cout << curStuNode->studentId << " " <<
             curStuNode->firstName << " " << curStuNode->lastName << endl;
        if( curStuNode->courseHead != NULL ){
            cout << "Course id Course name" << endl;
            CourseNode* curCourNode = curStuNode->courseHead;
            while( curCourNode != NULL ){
                cout << curCourNode->courseId << " " << curCourNode->courseName << endl;
                curCourNode = curCourNode->next;
            }
        }
        curStuNode = curStuNode->next;
    }
}