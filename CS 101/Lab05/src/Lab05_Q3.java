/*
 * This program inputs a minimum and maximum number of people and displays
 * the probabilities of at least 2 people have the same birthday.
 * Lab 05 Question 3
 * Author: Tarik Berkan Bilge
 * Date: 10.03.2021
 */
import java.util.Scanner;
public class Lab05_Q3
{
    public static void main( String[] args ) {

        double  probab;

        int     i,
                minVal,
                maxVal;

        Scanner userIn = new Scanner(System.in);
        //show message to user
        System.out.print( "Enter the minimum and maximum number of people: " );
        minVal = userIn.nextInt();
        maxVal = userIn.nextInt();

        //if values are written correctly
        if ( minVal >= maxVal ) {
            do {
                System.out.println( "Invalid input - minimum must be less than maximum..." );
                System.out.print( "Enter the minimum and maximum number of people: " );
                minVal = userIn.nextInt();
                maxVal = userIn.nextInt();
            }
            while ( minVal >= maxVal );
        }
        System.out.println( "NUMBER OF PEOPLE     PROBABILITY" );
        probab = 1;
        i = 0;
        do{
            do{
                i++;
                probab = probab * ( ( 365.0 - i ) / 365.0 );
            } while( i < minVal - 1 );
            System.out.printf( "%d %23.3f \n" , minVal , 1 - probab );
            minVal++;
        } while( minVal < maxVal + 1 );
    }
}