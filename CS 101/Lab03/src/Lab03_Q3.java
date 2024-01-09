/*
* This program inputs a string and an integer value from the user, and compares character of the string.
* Lab03 Question 3
* Author: Tarik Berkan Bilge
* Date: 24.02.2021
*/
import java.util.Scanner;
public class Lab03_Q3
{
    public static void main( String[] args ){

        //variables
        int     num,
                value;

        String  line,
                sentence;

        Scanner userIn = new Scanner( System.in );

        //display message to user
        System.out.print( "Enter a sentence: ");
        line = userIn.nextLine();

        //taking sentence without non-alphabetic
        if ( Character.isLetter( line.charAt( line.length() - 1 ) ) ){
            sentence = line;
        }
        else{
            sentence = line.substring( 0 , line.length() - 1 );
        }

        System.out.print( "Enter an integer value between 1 and " + line.length() + " : " );

        //value input
        if ( userIn.hasNextInt() ) {
            num = userIn.nextInt();
            //controlling the value
            if ( 1 < num && num < line.length() ) {
                value = num;
                //compare characters
                if ( sentence.substring( 0 , value ).equals( sentence.substring( sentence.length() - value ) ) ){
                    System.out.print( "First and last " + value + " characters are the same" );
                }
                else {
                    System.out.print("First and last " + value + " characters are not the same");
                }
            }
            else{
                System.out.print( "Error - value must be between 1 and " + line.length() );
            }
        }
        else{
            System.out.print( "Error - value must be an integer" );
        }
    }
}
