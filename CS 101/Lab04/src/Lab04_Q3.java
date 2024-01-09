/*
* This program determines if a word input by the user is a pair-word.
* Lab 04 Question 3
* Author: Tarik Berkan Bilge
* Date: 04.03.2021
*/
import java.util.Scanner;
public class Lab04_Q3
{
    public static void main( String[] args ){

        String  input,
                word;

        boolean twoTrue;

        char    ch1,
                ch2;

        int     counter,
                j,
                i;

        Scanner userIn = new Scanner( System.in );

        //display message to user
        System.out.print( "Enter a word: ");
        input = userIn.next();
        word = input.toLowerCase();

        i = 0;
        twoTrue = true;
        while ( i < word.length() && twoTrue == true ) {
                ch1 = word.charAt(i);

                j = 0;
                counter = 0;
                while (j < word.length()) {
                    ch2 = word.charAt(j);
                    //search same letters
                    if ( ch1 == ch2 ) {
                        counter++;
                    }
                    j++;
                }
                //same letter's frequency must be 2
                if( counter != 2){
                    twoTrue = false;
                }
                i++;
        }
        //display to user is the word pair or not
        if( twoTrue == true ){
            System.out.print( input + " is a pair-word!");
        }
        else{
            System.out.print( input + " is not a pair-word!");
        }
    }
}
