/**
 * Tarik Berkan Bilge
 * 22003392
 * Sec:2
 */

#include "AlgebraicExpression.h"

int precedence( char c ) {
    if ( c == '+' || c == '-' ) {
        return 1;
    }
    else if ( c == '*' || c == '/' ) {
        return 2;
    }
    return 0;
}

bool isOperator( char c ) {
    return ( c == '+' || c == '-' || c == '*' || c == '/' );
}

//it converts an infix expression to its equivalent postfix form
string infix2postfix( const string exp ){
    string postfix = "";
    stack<char> operators;

    for( char c : exp ) {
        switch( c ){
            case '0'...'9':
                postfix += c;  //append operands directly to the postfix string
                break;
            case '(':
                operators.push( c );  //push opening parenthesis to the stack
                break;
            case ')':
                while( !operators.empty() && operators.top() != '(' ) {
                    postfix += operators.top();
                    operators.pop();
                }
                if( !operators.empty() && operators.top() == '(' ) {
                    operators.pop();  //pop the corresponding opening parenthesis
                }
                break;
            case '*'...'/':
                while( !operators.empty() && precedence( c ) <= precedence( operators.top() ) ) {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(c);
                break;
        }
    }

    //append the remaining operators in the stack to the postfix string
    while( !operators.empty() ) {
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}

//it evaluates a postfix expression
double evaluatePostfix( const string exp ){
    stack<double> operands;

    for( char c : exp ) {
        if( isdigit( c ) ) {
            operands.push( c - '0' );  //convert char to integer and push to stack
        }
        else if ( isOperator( c ) ) {
            double operand2 = operands.top();
            operands.pop();

            double operand1 = operands.top();
            operands.pop();

            switch( c ){
                case '+':
                    operands.push( operand1 + operand2 );
                    break;
                case '-':
                    operands.push( operand1 - operand2 );
                    break;
                case '*':
                    operands.push( operand1 * operand2 );
                    break;
                case '/':
                    operands.push( operand1 / operand2 );
                    break;
            }
        }
    }
    return operands.top();
}