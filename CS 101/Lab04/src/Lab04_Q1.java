/*
* This program inputs the type of ball and the initial height and calculate and display how many times the ball will
bounce when dropped from its initial height before it rises to a height of less than 10 centimeters.
* Lab 04 Question 1
* Author: Tarik Berkan Bilge
* Date: 03.03.2021
*/
import java.util.Scanner;
public class Lab04_Q1
{
    public static void main( String[] args ){

        String  ballType;

        int     bounce;

        double  initialHeight,
                travel,
                height,
                coefficient;

        Scanner userIn = new Scanner( System.in );

        //display message to user
        System.out.print( "Enter Ball Type: " );
        ballType = userIn.nextLine();

        //determine coefficient
        coefficient = 0;
        //tennis ball
        if( ballType.equals( "Tennis Ball" ) ){
            coefficient = 0.7;
        }
        //basketball
        else if( ballType.equals( "Basketball" ) ){
            coefficient = 0.75;
        }
        //superball
        else if( ballType.equals( "Superball" ) ){
            coefficient = 0.9;
        }
        //softball
        else if( ballType.equals( "Softball" ) ){
            coefficient = 0.3;
        }
        //invalid input
        else {
            System.out.print( "Invalid Ball Type - Exiting..." );
        }

        //if the input invalid
        if( coefficient > 0 ){
            System.out.print( "Enter Initial Height (m): " );
            initialHeight = 0;

            while( !userIn.hasNextDouble() ) {
                System.out.println( "Height must be numeric value..." );
                System.out.print( "Enter Initial Height (m): " );
                userIn.nextLine();
            }

            initialHeight = userIn.nextDouble();

                    travel = 0;
                    bounce = 0;
                    height = initialHeight;
                    while ( height >= 0.1 ) {
                        height = height * coefficient;
                        bounce++;
                        //do not count under 10cm
                        if ( height >= 0.1 ) {
                            travel = travel + height;
                        }
                    }
                    //show results
                    System.out.println( "Number of bounces: " + bounce );
                    System.out.printf( "Meters travelled: %.2f", initialHeight + ( 2 * travel ) );
        }
    }
}
