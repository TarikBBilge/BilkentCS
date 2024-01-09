/*
* This program determines the age dependency category for a given country
* Lab03 Question 2
* Author: Tarik Berkan Bilge
* Date: 23.02.2021
*/
import java.util.Scanner;
public class Lab03_Q2
{
    public static void main( String[] args){

        //variables
        int     children,
                workingAdults,
                seniors;

        double  childDependency,
                seniorDependency;

        String category;

        Scanner userIn = new Scanner( System.in );

        //display message to user
        System.out.print( "Enter number citizen under 15: ");
        children = userIn.nextInt();

        System.out.print( "Enter number citizen between 15 and 64: ");
        workingAdults = userIn.nextInt();

        System.out.print( "Enter number citizen over 64: ");
        seniors = userIn.nextInt();

        childDependency = ( (double)children / workingAdults * 100 );
        seniorDependency = ( (double)seniors / workingAdults  * 100 );

        //categorizing
        if ( seniorDependency < 15 ){
            if ( childDependency < 29 ){
                category = "Low Overall Dependency";
            }
            else if ( childDependency < 45 ){
                category = "Moderate Child Dependency";
            }
            else {
                category = "High Child Dependency";
            }
        }
        else {
            if ( childDependency >= 29 ){
                category = "Double Dependency";
            }
            else{
                category = "High Old-age Dependency";
            }
        }
        System.out.println();
        System.out.printf( "Child Dependency: %.1f\n" , childDependency );
        System.out.printf( "Senior Dependency: %.1f\n" , seniorDependency );
        System.out.print( "Age Dependency Category: " + category );
    }
}
