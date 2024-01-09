/*
 * This class represents a rectangle which its bottom left corner on (0, 0) point
 *
 * Author: Tarik Berkan Bilge
 * Date: 13/10/2021
 */

public class Rectangle
{
    //variables
    public int width;
    public int height;

    //constructor
    public Rectangle( int width, int height ) {
        Point corner = new Point( 0, 0 );
        this.width = width;
        this.height = height;
    }

    //accessors
    public int getWidth() {
        return width;
    }
    public int getHeight() {
        return height;
    }

    //mutators
    public void setWidth( int width ) {
        this.width = width;
    }
    public void setHeight( int height ) {
        this.height = height;
    }

    //methods

    /**
     * This method determines if a point is inside or outside of the rectangle
     * @param point is a point coming from Point class
     * @return if the point is inside the rectangle
     */
    public boolean contains( Point point ){
        if( point.getX() < getWidth() && point.getY() < getHeight() ){
            return true;
        }
        return false;
    }

    /**
     * This method generates a random point
     * @return randPoint which is random point
     */
    public Point getRandomPoint(){

        double a;
        double b;

        a = Math.random() * getWidth();
        b = Math.random() * getHeight();

        Point randPoint = new Point( a, b );

        return randPoint;
    }

    /**
     * This method displays string representation of rectangle
     * @return rectangle representation
     */
    public String toString(){
        String rect = "Width of rectangle is " + getWidth() +
                ", and height of rectangle is " + getHeight();
        return rect;
    }
}
