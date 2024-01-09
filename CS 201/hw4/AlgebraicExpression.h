/**
 * Tarik Berkan Bilge
 * 22003392
 * Sec:2
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

#ifndef HW4_ALGEBRAICEXPRESSION_H
#define HW4_ALGEBRAICEXPRESSION_H

//additional functions
int precedence( char c );
bool isOperator( char c );

string infix2postfix ( const string exp );
double evaluatePostfix ( const string exp );

#endif //HW4_ALGEBRAICEXPRESSION_H