/*
*Lab02 Question 2
*This program inputs a monthly salary from the user and calculates and displays a table.
*Author: Tarik Berkan Bilge
*Date: 16.02.2021
*/
import java.util.Scanner;
public class Lab02_Q2
{
    public static void main( String[] args ) {

        //variable
        int monthlySalary;

        Scanner input = new Scanner( System.in );

        //Display message to user
        System.out.print( "Enter monthly salary: " );
        monthlySalary = input.nextInt();

        //Calculations
        System.out.println( "---------------------------------------------");
        System.out.printf( "|Housing %14%%d %17.2f | \n" , 30 , monthlySalary * 30.0 / 100 );
        System.out.printf( "|Food %17%%d %17.2f | \n" , 15 , monthlySalary * 15.0 / 100 );
        System.out.printf( "|Transport %12%%d %17.2f | \n" , 20 , monthlySalary * 20.0 / 100 );
        System.out.printf( "|Savings %14%%d %17.2f | \n" , 18 , monthlySalary * 18.0 / 100 );
        System.out.printf( "|%26s %15.2f | \n" , "TOTAL" , monthlySalary * 83.0 / 100 );
        System.out.printf( "|%30s %11.2f | \n" , "REMAINING" , monthlySalary * 17.0 / 100 );
        System.out.println( "---------------------------------------------");
    }
}
