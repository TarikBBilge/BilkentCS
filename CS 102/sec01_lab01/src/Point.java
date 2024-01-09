/*
 * This class creates a point
 *
 * Author: Tarik Berkan Bilge
 * Date: 13/10/2021
 */

public class Point
{
    //variables
    private double x;
    private double y;

    //constructor
    public Point( double x, double y ) {
        this.x = x;
        this.y = y;
    }

    //accessors
    public double getX() {
        return x;
    }
    public double getY() {
        return y;
    }

    //mutators
    public void setX( double x ) {
        this.x = x;
    }
    public void setY( double y ) {
        this.y = y;
    }

    //methods

    /**
     * This method displays string representation of point
     * @return point representation
     */
    public String toString(){
        String point = "(" + getX() + ", " + getY() + ")";
        return point;
    }
}
