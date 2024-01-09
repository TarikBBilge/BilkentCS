/*
*Lab02 Question 3
*This program inputs a date and time in the given format and outputs in another format.
*Author: Tarik Berkan Bilge
*Date: 17.02.2021
*/
import java.util.Scanner;
public class Lab02_Q3
{
    public static void main( String[] args ){

        //Variables
        String  dateAndTime,
                weekday,
                hour,
                minute,
                day,
                year,
                month;

        int     firstSlashPosition,
                secondSlashPosition,
                commaPosition,
                dashPosition,
                colonPosition;

        Scanner input = new Scanner( System.in );

        //Display message to user
        System.out.print( "Enter date and time: ");
        dateAndTime = input.nextLine();

        //splitting inputs
        firstSlashPosition = dateAndTime.indexOf( "/" );
        secondSlashPosition = dateAndTime.indexOf( "/" , firstSlashPosition + 1 );
        year = dateAndTime.substring( 0, firstSlashPosition );
        month = dateAndTime.substring( firstSlashPosition + 1 , secondSlashPosition );

        commaPosition = dateAndTime.indexOf( "," );
        day = dateAndTime.substring( secondSlashPosition + 1 , commaPosition );

        dashPosition = dateAndTime.indexOf( "-" );
        weekday = dateAndTime.substring( commaPosition + 1 , dashPosition );

        colonPosition = dateAndTime.indexOf( ":" );
        hour = dateAndTime.substring( dashPosition + 1 , colonPosition );

        minute = dateAndTime.substring( colonPosition + 1 );

        //Date and time in another format
        System.out.println( weekday + " " + month + " " + day + "," + year + " " + minute + " minutes past " + hour );

    }

}
