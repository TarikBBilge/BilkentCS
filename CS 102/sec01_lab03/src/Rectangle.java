/*
 * This class represents a rectangle which its bottom left corner on (0, 0) point
 *
 * Author: Tarik Berkan Bilge
 * Date: 13/10/2021
 */

public class Rectangle extends Shape
{
    //variables
    public int width;
    public int height;

    //constructor
    public Rectangle( int width, int height ) {
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
     * This method displays string representation of rectangle
     * @return rectangle representation
     */
    public String toString(){
        String rect = "Width of rectangle is " + getWidth() +
                ", and height of rectangle is " + getHeight() + " " + getSelected();
        return rect;
    }

    /**
     *
     * @return
     */
    @Override
    public double getArea() {
        double area;

        area = getWidth() * getHeight();

        return area;
    }

    @Override
    public double getX() {
        return this.getX();
    }

    @Override
    public double getY() {
        return this.getY();
    }

    @Override
    public void setLocation( double x, double y ) {

    }

    @Override
    public boolean getSelected() {
        return false;
    }

    @Override
    public void setSelected(boolean selected) {

    }

    @Override
    public Shape contains( int x, int y ) {
        if( Math.abs( this.getX() - x ) < this.getWidth() && Math.abs( this.getY() - y ) < this.getHeight() ){
            return this;
        }
        return null;
    }
}

class Square extends Rectangle{
    int side;

    public Square( int side ){
        super( side,side );
        this.side = side;
    }

    public int getSide() {
        return side;
    }

    @Override
    public double getArea() {
        double area;

        area = side * side;

        return area;
    }

    @Override
    public Shape contains(int x, int y) {
        if( Math.abs( this.getX() - x ) < this.getSide() && Math.abs( this.getY() - y ) < this.getSide() ){
            return this;
        }
        return null;
    }

    @Override
    public String toString() {
        return "Length of one side of the square: " + this.side + getSelected();
    }
}
