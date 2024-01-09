/*
 * This class creates a circle and shows
 * relationship between a point
 *
 * Author: Tarik Berkan Bilge
 * Date: 13/10/2021
 */

public class Circle
{
    //variables
    public int radius;
    Point center;

    //constructor
    public Circle( int radius, Point center ) {
        this.radius = radius;
        this.center = center;
    }

    //accessors
    public int getRadius() {
        return radius;
    }
    public Point getCenter() {
        return center;
    }

    //mutators
    public void setRadius( int radius ) {
        this.radius = radius;
    }
    public void setCenter( Point center ) {
        this.center = center;
    }

    //methods

    /**
     * This method determines if a point is inside or outside of the circle
     * @param point is a point coming from Point class
     * @return if the point is inside the circle
     */
    public boolean contains( Point point ){
        if( ( point.getX() - getRadius() ) * ( point.getX() - getRadius() ) +
                ( point.getY() - getRadius() ) * ( point.getY() - getRadius() ) <= getRadius() * getRadius() ){
            return true;
        }
        return false;
    }

    /**
     * This method displays string
     * @return circle is a string representation of circle
     */
    public String toString(){
        String circle;
        circle = "Radius of circle is " + getRadius() + ", and center point of circle is " +
                getCenter().toString(); //(?)
        return circle;
    }
}
