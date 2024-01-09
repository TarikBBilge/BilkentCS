/*
 * This program executes Time class and take times from user and schedules doctor appointment.
 * Lab 9 TimeApp
 * Author: Tarik Berkan Bilge
 * Date: 29.04.2021
 */
import java.util.ArrayList;
import java.util.Scanner;
public class TimeApp
{
    static void sortAppointments( ArrayList<Time> times ){
        int     i,
                j;

        for( i = 0; i < times.size(); i++ ){
            Time key = times.get( i );
            j = i - 1;
            while( ( j > 0 ) && key.lessThan( times.get( j ) ) ){
                times.set( j + 1, times.get( j ) );
                j = j - 1;
            }
            times.set( j + 1 , key );
        }
    }
    static void printAppointments( ArrayList<Time> times ){
        for( int i = 0; i < times.size(); i++ ){
            System.out.println( times.get( i ) );
        }
    }

    public static void main( String[] args ){
        String delay;

        int latency;

        ArrayList<Time> appoTimes = new ArrayList<Time>();

        Scanner userIn = new Scanner( System.in );

        for( int i = 0; i < 7; i++ ){
            userIn.useDelimiter( ":|\\n" );
            System.out.print( "Enter appointment time: " );
            Time appointment = new Time( userIn.nextInt(), userIn.nextInt() );
            appoTimes.add( appointment );
        }
        System.out.println( "\nScheduled Appointments: " );
        printAppointments( appoTimes );

        System.out.print( "\nWhen will delay start (M)orning / (A)fternoon: " );
        delay = userIn.next();
        System.out.print( "How many minutes will the doctor be late: " );
        latency = userIn.nextInt();

        //if latency starts at morning
        if( delay.equals( "M" ) ){
            for( int j = 0; j < appoTimes.size(); j++ ){
                appoTimes.get( j ).addTime( latency );
            }
        }
        //if latency starts afternoon
        else if( delay.equals( "A" ) ){
            for( int j = 0; j < appoTimes.size(); j++ ){
                if( !appoTimes.get( j ).lessThan( new Time( 12,30 ) ) ){
                    appoTimes.get( j ).addTime( latency );
                }
            }
        }
        sortAppointments( appoTimes );

        System.out.println( "\nUpdated appointments: " );
        printAppointments( appoTimes );
    }
}
