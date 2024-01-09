/*
 * A simple program to fix syntax errors.
 * 
 * This program prints information about the lab schedule and grading policy.
 * CS101 Lab01 Question 1
 * @author Tarik Berkan Bilge
 * @date   02/09/2021
 */
public class Lab01_Q1
{   
   
   public static void main( String[] args )
   {
      // Constants
      final double GRADE_PERCENT = 0.25;  // grading policy
      final int LAB_COUNT = 10;
      final double GRADE_PER_LAB = (GRADE_PERCENT / LAB_COUNT * 100);
       
      // Variables
      String courseSemester;     
      
      /* This program prints information about the lab
         schedule and grading policy */
           
      // First initialize the lab information
      courseSemester = ("CS101 SPRING 2021") ;
      
      // Print out this lab section info
      System.out.println( "Hello everyone, below are some course details" );
      System.out.println( "Welcome to " + courseSemester + " Lab 01" );
      
      // Print out the grading policy
      System.out.println( "There are: "+ LAB_COUNT + " lab sessions in this course." );
      System.out.println( "Labs contribute to " + GRADE_PERCENT * 100 + "% of your total grade." );
      System.out.println( "This lab :\t" + GRADE_PER_LAB + "\t points" );
      System.out.println( "All lab :\t" + GRADE_PERCENT * 100 + "\t points" );
      System.out.println( "Please come prepared..." );
      
      // Wish them luck and finish
      System.out.println("");
      System.out.println( "Good luck!" );      
   }
   
}
