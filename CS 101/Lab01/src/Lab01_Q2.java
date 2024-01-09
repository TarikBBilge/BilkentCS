/*
 *
 * This program prints some calculations.
 * CS101 Lab01 Question 2
 * @author Tarik Berkan Bilge
 * @date   02/09/2021
 */
public class Lab01_Q2
{
    public static void main( String[] args )
    {
        double x, y, z;

        //Calculations
        x = (( 23.2 - 7.1 / 2.2 ) / (( 5.1 - 3.7 ) * ( 3.4 + 4.2 )));
        y = (( 35.7 * 64.1 - Math.pow( 6.0, 3 )) / ( 43 + Math.pow( 5, 2 ) ));
        z = Math.pow( 2.1 + 8.0, -1.0 / 3 );

        //Answers
        System.out.println( "Answer1 is:" + x );
        System.out.println( "Answer2 is:" + y );
        System.out.println( "Answer3 is:" + z );
    }

}
