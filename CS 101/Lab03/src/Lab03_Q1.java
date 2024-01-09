/*
* This program calculates and displays the rounded sum of 2 values input by the user.
* Lab03 Question 1
* Author: Tarik Berkan Bilge
* Date: 22.02.2021
*/
import java.util.Scanner;
public class Lab03_Q1
{
    public static void main( String[] args ){

        //variables
        int     val1,
                val2,
                roundedVal1,
                roundedVal2,
                sum;

        //display message to user
        System.out.print( "Enter two numbers: " );

        Scanner userIn = new Scanner( System.in );
        val1 = userIn.nextInt();
        val2 = userIn.nextInt();

        //rounding value 1
        if ( val1 % 10 >= 5 ){
            roundedVal1 = val1 + 10 - val1 % 10;
        }
        else {
            roundedVal1 = val1 - val1 % 10;
        }

        //rounding value 2
        if ( val2 % 10 >= 5 ){
            roundedVal2 = val2 + 10 - val2 % 10;
        }
        else {
            roundedVal2 = val2 - val2 % 10;
        }

        //sum of the values
        if  ( roundedVal1 % 3 == 0 ){
            sum = roundedVal1 + val2;
        }
        else{
            sum = roundedVal1 + roundedVal2;
        }

        System.out.println( "The sum of the rounded values of " + val1 + " and " + val2 + ": " + sum );
    }
}
