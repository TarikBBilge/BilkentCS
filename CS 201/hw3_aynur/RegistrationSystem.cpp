/**
 * Tarik Berkan Bilge
 * Sec: 2
 * 22003392
 */

#include "RegistrationSystem.h"

RegistrationSystem::RegistrationSystem(){
    stuHeadPtr = NULL;
    stuCount = 0;
}

RegistrationSystem::~RegistrationSystem(){

}

void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName){
    //add the first student
    if( stuCount == 0 ){
        Student stuObj( studentId, firstName, lastName );
        //stuObj.setCourseCount( 0 );
        //stuObj.setCourseHeadPtr(NULL);

        DoublyNode* stuNode = new DoublyNode();
        stuNode->setItem(stuObj );
        stuHeadPtr = stuNode;
        stuCount++;
        cout << "Student " << studentId << " has been added" << endl;
    }
    else{
        DoublyNode* cur = stuHeadPtr;
        DoublyNode* prev = stuHeadPtr->getPrev();
        //cur->setPrev( prev );
        while( cur != NULL ){ //if the student already exists
            if( cur->getItem().getStuId() == studentId ){
                cout << "Student " << studentId << " already exists" << endl;
                return;
            }
            cur = cur->getNext();
            prev = prev->getNext();
        }

        //add the new student
        Student stuObj( studentId, firstName, lastName );
        //stuObj.setCourseCount( 0 );
        //stuObj.setCourseHeadPtr(NULL);

        DoublyNode* stuNode = new DoublyNode();
        stuNode->setItem(stuObj );

        while( cur != NULL && cur->getItem().getStuId() < studentId ){
            prev = cur;
            cur = cur->getNext();
        }

        if( prev == NULL ){
            stuNode->setNext( stuHeadPtr );
            stuHeadPtr = stuNode;
        }
        else{
            stuNode->setNext( cur );
            prev->setNext( stuNode );
        }
        stuCount++;
        cout << "Student " << studentId << " has been added" << endl;
    }
}

void RegistrationSystem::deleteStudent(const int studentId) {

}

void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName){
    DoublyNode* curStu = stuHeadPtr;
    while( curStu != NULL ){
        Student temp = curStu->getItem();
        if( temp.getStuId() == studentId ){    //if the student exists
            if( curStu->getItem().getCourseHeadPtr() == NULL ){     //if it is the first course of the student
                Course courseObj( studentId, courseId, courseName );
                Node* courseNode = new Node();
                courseNode->setItem( courseObj );

                temp.setCourseHeadPtr( courseNode );
                //cout << temp.getCourseHeadPtr() << endl;
                temp.setCourseCount(temp.getCourseCount() + 1);
                curStu->setItem( temp );
                //cout << curStu->getItem().getCourseHeadPtr() << endl;

                //curStu->getItem().setCourseHeadPtr( courseNode );
                cout << "Course " << courseId << " has been added to student " << studentId << endl;
                //curStu->getItem().setCourseCount( curStu->getItem().getCourseCount() + 1 );
                cout << temp.getCourseCount() << endl;
                return;
            }
            else{   //if it is not the first course of the student
                Node* curCourse = temp.getCourseHeadPtr();
                Node* prevCourse = NULL;
                while( curCourse != NULL ){     //if the course already exists
                    if( curCourse->getItem().getCourId() == courseId ){
                        cout << "Student " << studentId << " is already enrolled in course " << courseId << endl;
                        return;
                    }
                    curCourse = curCourse->getNext();
                }
                //add the course to the student
                Course courseObj( studentId, courseId, courseName );
                Node* courseNode = new Node();
                courseNode->setItem( courseObj );

                while( curCourse != NULL && curCourse->getItem().getCourId() < courseId ){
                    prevCourse = curCourse;
                    curCourse = curCourse->getNext();
                }
                if (prevCourse == NULL) {
                    courseNode->setNext( curStu->getItem().getCourseHeadPtr() );
                    temp.setCourseHeadPtr( courseNode );
                }
                else {
                    courseNode->setNext( curCourse );
                    prevCourse->setNext( courseNode );
                }
                cout << "Course " << courseId << " has been added to student " << studentId << endl;
                temp.setCourseCount( temp.getCourseCount() + 1 );
                cout << temp.getCourseCount() << endl;
                return;
            }
        }
        curStu = curStu->getNext();
    }
    //if the student does not exist
    cout << "Student " << studentId << " does not exist" << endl;
}

void RegistrationSystem::withdrawCourse(const int studentId, const int courseId){

}

void RegistrationSystem::cancelCourse(const int courseId){

}

void RegistrationSystem::showStudent(const int studentId){
    DoublyNode* curStuNode = stuHeadPtr;
    cout << "Student id First name Last name" << endl;
    while( curStuNode != NULL ){
        cout << curStuNode->getItem().getStuId() << " " <<
        curStuNode->getItem().getFName() << " " << curStuNode->getItem().getLName() << endl;
        curStuNode = curStuNode->getNext();
    }
}

void RegistrationSystem::showCourse(const int courseId){

}

void RegistrationSystem::showAllStudents(){
    DoublyNode* curStuNode = stuHeadPtr;
    cout << "Student id First name Last name" << endl;
    while( curStuNode != NULL ){
        cout << curStuNode->getItem().getStuId() << " " <<
             curStuNode->getItem().getFName() << " " << curStuNode->getItem().getLName() << endl;
    }
}