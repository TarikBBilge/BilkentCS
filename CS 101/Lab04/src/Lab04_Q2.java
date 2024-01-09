/*
*This program calculates the sine of an input value x radian degree.
* Lab 04 Question 2
* Author: Tarik Berkan Bilge
* Date: 03.03.2021
*/
import java.util.Scanner;
public class Lab04_Q2
{
    public static void main( String[] args ){

        //x is radian degree of sine
        double  sinX,
                element,
                x;

        int     fac,
                i,
                n;

        Scanner userIn = new Scanner( System.in );

        //display message to user
        System.out.print( "Enter degree you want find sine of it: " );
        x = userIn.nextDouble();
        x = x % 3.1415926535;

        System.out.print( "Enter n (odd number) value (higher the n the more precise the result): ");
        n = userIn.nextInt();

        fac = 1;
        sinX = 0;
        i = 1;
        while ( i <= n )
        {
            element = Math.pow ( x, i ) / fac;

            //determining subtractions
            if ( i % 4 == 3 )
            {
                sinX = sinX - element ;
            }
            else
            {
                sinX = sinX + element ;
            }

            fac = fac * ( i + 1 ) * ( i + 2 );
            i = i + 2;
        }

            System.out.print( "sin x = " + sinX );
        }
    }

