/*
* This program sums all digits in the string.
* Lab 05 Question 1a
* Author: Tarik Berkan Bilge
* Date: 10.03.2021
*/
import java.util.Scanner;
public class Lab05_Q1_a
{
    public static void main( String[] args ){

        int     digit,
                i,
                sum;

        char    ch;

        boolean containsDigit;

        String  sentence;

        Scanner userIn = new Scanner( System.in );

        //show message to user
        System.out.print( "Enter a sentence: " );
        sentence = userIn.nextLine();

        sum = 0;
        containsDigit = false;
        for( i = 0; i < sentence.length(); i++ ){
            ch = sentence.charAt( i );

            //if current character is digit
            if( Character.isDigit( ch ) ){
                digit = Character.getNumericValue( ch );
                containsDigit = true;
                sum += digit;
            }
        }
        //if the sentence has not digit
        if( containsDigit == false ){
            System.out.print( "No numeric characters exist in the input string" );
        }
        else{
            System.out.print( "The sum of the digits is: " + sum );
        }
    }
}
