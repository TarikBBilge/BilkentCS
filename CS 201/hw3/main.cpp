#include <iostream>
using namespace std;

#include "RegistrationSystem.h"
int main () {
    RegistrationSystem rs;

    rs.addStudent(2000, "Kemal", "Ak");
    rs.addStudent(1000, "Nuri", "Yazici");
    rs.addStudent(4000, "Cengiz", "Erdem");

    rs.addCourse(2000, 555, "CS555");
    rs.addCourse(2000, 555, "CS555");
    rs.addCourse(2000, 540, "CS540");

    rs.addCourse(1000, 555, "CS555");
    rs.addCourse(1000, 520, "CS520");
    rs.addCourse(1000, 540, "CS540");

    rs.addCourse(4000, 540, "CSS540");
    rs.addCourse(4000, 540, "CS540");

    rs.withdrawCourse(4000, 520);
    rs.withdrawCourse(1000, 520);
    rs.cancelCourse(520);
    rs.withdrawCourse(2000, 540);
    rs.withdrawCourse(1000, 540);
    rs.withdrawCourse(4000, 540);

    rs.addCourse(6000, 540, "CS540");
    rs.addCourse(4000, 540, "CSS540");
    rs.addCourse(4000, 540, "CS540");
    rs.addCourse(1000, 540, "CSS540");

    rs.cancelCourse(540);
    rs.withdrawCourse(1000, 540);
    rs.withdrawCourse(1000, 520);
    rs.withdrawCourse(1000, 555);
    //cout << endl ;
    /*
    rs. showAllStudents ();
    rs. addStudent (2000 , "Kemal", "Ak");
    rs. addStudent (1000 , "Nuri", "Yazici");
    rs. addStudent (4000 , "Cengiz", "Erdem");
    rs. addStudent (3000 , "Osman", "Top");
    rs. addStudent (4000 , "Can", "Gezici");
    rs. addStudent (6000 , "Can", "Gezici");
    rs. addStudent (5000 , "Ali", "Akdere");
    rs. addStudent (7000 , "Burcin", "Temiz");
    //cout << endl ;
    rs. showAllStudents ();
    //cout << endl ;
    rs. addCourse (2000 , 555 , "CS555");
    rs. addCourse (2000 , 540 , "CS540");
    rs. addCourse (2000 , 513 , "CS513");
    rs. addCourse (2000 , 524 , "CS524");
    rs. addCourse (3000 , 524 , "CS524");
    rs. addCourse (3000 , 540 , "CS540");
    rs. addCourse (1000 , 540 , "CS540");
    rs. addCourse (1000 , 524 , "CS524");
    rs. addCourse (4000 , 524 , "CS524");
    rs. addCourse (4000 , 510 , "CS510");
    rs. addCourse (4000 , 540 , "CS540");
    rs. addCourse (4000 , 513 , "CS513");
    rs. addCourse (5000 , 510 , "CS510");
    rs. addCourse (5000 , 513 , "CS513");
    rs. addCourse (5000 , 540 , "CS540");
    rs. addCourse (6000 , 540 , "CS540");
    rs. addCourse (7000 , 510 , "CS510");
    rs. addCourse (7000 , 513 , "CS513");

    rs. addCourse (7000 , 540 , "CS540");
    rs. addCourse (3000 , 524 , "CS524");
    //cout << endl ;

    rs. deleteStudent (5000) ;
    rs. deleteStudent (5000) ;
    //cout << endl ;
    rs. showStudent (1000) ;
    rs. showStudent (3000) ;
    rs. showStudent (5000) ;
    //cout << endl ;
    rs. showAllStudents ();
    //cout << endl ;
    rs. withdrawCourse (3000 , 524) ;
    rs. withdrawCourse (2000 , 555) ;
    rs. withdrawCourse (2000 , 550) ;
    rs. withdrawCourse (10000 , 510) ;
    //cout << endl ;
    rs. cancelCourse (540) ;
    rs. cancelCourse (201) ;
    //cout << endl ;
    rs. showCourse (524) ;
    //cout << endl;
    rs. showCourse (540) ;
    //cout << endl;
    rs. showStudent (7000) ;
    //cout << endl ;
    rs. deleteStudent (7000) ;
    //cout << endl ;
    rs. showStudent (3000) ;
    //cout << endl ;
    rs. showAllStudents ();
    //cout << endl ;*/
    return 0;
}