/*
*Lab02 Question 1
*This program inputs a value from the user and calculates and displays output.
*Author: Tarik Berkan Bilge
*Date: 15.02.2021
*/
import java.util.Scanner;
public class Lab02_Q1
{
    public static void main( String[] args ) {

        //variables
        double measurement;

        Scanner input = new Scanner( System.in );

        //Display message to user
        System.out.print( "Enter measurement in millimeters: " );
        measurement = input.nextDouble();

        //Measurements in another format
        System.out.printf( "Micrometers: %10.3f\n" , measurement * 1000 );
        System.out.printf( "Millimeters: %10.3f\n" , measurement );
        System.out.printf( "Centimeters: %10.3f\n" , measurement / 10 );
        System.out.printf( "Meters     : %10.3f\n" , measurement / 1000 );
    }
}
