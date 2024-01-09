/*
 * This program inputs a nucleic acid sequence and displays its encoded form.
 * Lab 05 Question 2
 * Author: Tarik Berkan Bilge
 * Date: 10.03.2021
 */
import java.util.Scanner;
public class Lab05_Q2
{
    public static void main( String[] args ){

        int     pointer,
                frequency = 0;

        String  sequence;

        Scanner userIn = new Scanner( System.in );

        //show message to user
        System.out.print( "Enter a nucleic acid sequence: " );
        sequence = userIn.next();

        for( pointer = 0; pointer < sequence.length(); pointer++ ){
            frequency = 1;
            //I use if as we have to do without while loop
            if( pointer + 1 < sequence.length() && sequence.charAt( pointer ) == sequence.charAt( pointer + 1 ) ) {
                do {
                    pointer++;
                    frequency++;
                } while( pointer + 1 < sequence.length() && sequence.charAt( pointer ) == sequence.charAt( pointer + 1 ) );
            }
            System.out.print( sequence.charAt( pointer ) );
            System.out.print( frequency );
        }
    }
}