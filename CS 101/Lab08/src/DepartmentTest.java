/*
 * This program tests .equals and compares with system .equals
 * Lab 08 Department Test
 * Author: Tarik Berkan Bilge
 * Date: 15.04.2021
 */
public class DepartmentTest
{
    public static void main( String[] args ){
        Department d1 = new Department( "Information Technology Dept", "IT" );
        Department d2 = d1;

        Department d3 = new Department( "Human Resources Dept", "HR" );
        Department d4 = new Department( "Information Technology Dept", "IT" );

        //==
        System.out.println( "==" );
        System.out.println( d1==d2 );
        System.out.println( d1==d3 );
        System.out.println( d2==d4 );
        System.out.println( d1==d4 );

        //.equals()
        System.out.println( ".equals" );
        System.out.println( d1.equals( d2 ) );
        System.out.println( d1.equals( d3 ) );
        System.out.println( d2.equals( d4 ) );
        System.out.println( d1.equals( d4 ) );
    }
}
