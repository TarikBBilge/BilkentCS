# include <iostream>
# include "AlgebraicExpression.h"
#include "iomanip"

int main () {
    cout << infix2postfix("(3+5) -8*4") << endl ;
    cout << evaluatePostfix("653 -8*+2/") << endl ;
    cout << infix2postfix ("(3+5)-8*4") << endl ;//35+84*-
    cout << fixed << setprecision(2) <<  evaluatePostfix ("653-8*+2/") << endl;//11.00
    cout << fixed << setprecision(2) <<  evaluatePostfix ("52/3*") << endl;//7.50
    cout << infix2postfix ("(5/2)*3") << endl ;//52/3*
    cout << fixed << setprecision(2) <<  evaluatePostfix (infix2postfix ("3-2*2")) << endl;//-1.00
    return 0;
}
