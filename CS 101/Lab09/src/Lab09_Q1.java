/*
 * This program takes integers and divisor from user and returns integer list and divisible sum.
 * Lab 9 Question 1
 * Author: Tarik Berkan Bilge
 * Date: 28.04.2021
 */
import java.util.Scanner;
import java.util.ArrayList;
public class Lab09_Q1
{
    static void sumDivisible( ArrayList<Integer> list1, ArrayList<Integer> list2, int divisor ){
        int sum = 0,
            i;

        for( i = 0; i < list1.size(); i++ ){
            //if the integer is its divisor
            if( list1.get( i ) % divisor != 0 ){
                list2.add( sum );
            }
            else{
                sum = sum + list1.get( i );
                list2.add( sum );
            }
        }
    }
    static void fillList( ArrayList<Integer> list1 ){

        Scanner userIn = new Scanner( System.in );

        System.out.println( "Enter values:" );

        while( userIn.hasNextInt() ){
            list1.add( userIn.nextInt() );
        }
    }
    static void removeDuplicates( ArrayList<Integer> list2 ){
        for( int i = 0; i < list2.size(); i++ ){
            int c = i + 1;
            while( c < list2.size() ){
                //if they are same
                if( list2.get( i ).equals( list2.get( c ) ) ){
                    list2.remove( c );
                }
                else{
                    c++;
                }
            }
        }
    }

    public static void main( String[] args ){
        int divisor;

        Scanner userIn = new Scanner( System.in );

        ArrayList<Integer> numbers = new ArrayList<Integer>();
        fillList( numbers );


        System.out.println( "List: " + numbers );
        System.out.print( "Enter divisor: " );
        divisor = userIn.nextInt();

        ArrayList<Integer> sums = new ArrayList<Integer>();
        sumDivisible( numbers, sums, divisor );

        System.out.println( "Sum List: " + sums );

        removeDuplicates( sums );
        System.out.print( "Sum List (no duplicates): " + sums );
    }
}
