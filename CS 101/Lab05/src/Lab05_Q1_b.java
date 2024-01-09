/*
* This program displays each three-digit narcissistic number and their sum.
* Lab 05 Question 1b
* Author: Tarik Berkan Bilge
* Date: 10.03.2021
*/
public class Lab05_Q1_b
{
    public static void main( String[] args ){

        int     sum,
                unitsDigit,
                tensDigit,
                hundredsDigit,
                number;

        sum = 0;
        for( number = 100; number < 999; number++ ){

            unitsDigit = number % 10;
            tensDigit = ( number % 100 - unitsDigit ) / 10;
            hundredsDigit = number / 100;
            //if the number is narcissistic number
            if( number == Math.pow( unitsDigit , 3 ) + Math.pow( tensDigit , 3 ) + Math.pow( hundredsDigit , 3 ) ){
                System.out.println( number + " is a narcissistic number" );
                sum += number;
            }
        }
        System.out.print( "Sum of three-digit narcissistic numbers: " + sum );
    }
}
