/*
 * This class is main class, and asks to user
 * how many trial the user wants try, and shows estimate value of pi
 * according to trial number.
 *
 * Author: Tarik Berkan Bilge
 * Date: 13/10/2021
 */

import java.util.Scanner;
public class PiCalculator
{
    public static void main( String[] args ){

        Scanner userIn = new Scanner( System.in );

        Rectangle rectangle = new Rectangle( 2, 2 );
        Circle circle = new Circle( 1, new Point( 1, 1 ) );

        //ask user how many trial number to try
        System.out.println( "Enter trial number to try:" );
        long num = userIn.nextLong();

        long hit = 0;
        long trial = 0;

        for( int i = 0; i < num; i++ ) {
            if( rectangle.contains( rectangle.getRandomPoint() ) ){
                if( circle.contains( rectangle.getRandomPoint() ) ){
                    hit++;
                    trial++;
                }
                else{
                    trial++;
                }
            }
        }
        //show the estimate value of pi to user
        System.out.println( "Approximate value of pi is: " + ( ( double )hit / trial ) * 4 );
    }
}
