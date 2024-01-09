/*
 * This program provides methods to TimeApp main program
 * Lab 9 Time class
 * Author: Tarik Berkan Bilge
 * Date: 29.04.2021
 */
public class Time
{
    int     hours,
            minutes;

    //constructor method
    public Time( int hours, int minutes ){
        this.hours = hours;
        this.minutes = minutes;
    }
    //getter setter methods
    public int getHours(){
        return hours;
    }
    public void setHours( int hours ) {
        this.hours = hours;
    }
    public int getMinutes() {
        return minutes;
    }
    public void setMinutes( int minutes ) {
        this.minutes = minutes;
    }

    public void addTime( int passTime ){
        hours = hours + passTime / 60;
        minutes = minutes + passTime % 60;
        //minutes cannot be greater than 60
        if( minutes >= 60 ){
            hours = hours + ( minutes / 60 );
            minutes = minutes - 60;
        }
        //hours cannot be greater than 23
        if( hours > 23 ){
            hours = hours - 24;
        }
    }
    public boolean lessThan( Time time2 ){
        //if time2 is later
        if( this.getHours() < time2.getHours() ){
            return true;
        }
        else if( this.getHours() == time2.getHours() ){
            //if time2 is later
            if( this.getMinutes() < time2.getMinutes() ){
                return true;
            }
            //if time2 is earlier
            else{
                return false;
            }
        }
        return false;
    }
    public String toString(){
        String timeStr;
        //there is 0 before digit
        if( hours >= 10 && minutes >= 10 ) {
            timeStr = hours + ":" + minutes;
        }
        else if( hours >= 10 && minutes < 10 ){
            timeStr = hours + ":0" + minutes;
        }
        else if( hours < 10 && minutes >= 10 ){
            timeStr = "0" + hours + ":" + minutes;
        }
        else{
            timeStr = "0" + hours + ":0" + minutes;
        }
        return timeStr;
    }
}
