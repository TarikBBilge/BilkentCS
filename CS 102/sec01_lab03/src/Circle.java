/*
 *
 *
 * Author: Tarik Berkan Bilge
 * Date: 13/10/2021
 */

import shapes.Shape;

public class Circle extends Shape
{
    //variables
    public int radius;
    boolean isSelected;

    //constructor
    public Circle( int radius ) {
        this.radius = radius;
    }

    //accessors
    public int getRadius() {
        return radius;
    }

    //mutators
    public void setRadius( int radius ) {
        this.radius = radius;
    }

    //methods
    public double getArea(){
        double area;

        area = radius * radius * Math.PI;

        return area;
    }
    /**
     * This method displays string
     * @return circle is a string representation of circle
     */
    public String toString(){
        String circle;

        circle = "Circle with " + this.getRadius() + "px radius. " + getSelected();

        return circle;
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
        x = this.getX();
        y = this.getY();
    }

    @Override
    public boolean getSelected() {
        return this.isSelected;
    }

    @Override
    public void setSelected( boolean selected ) {
        this.isSelected = selected;
    }

    @Override
    public Shape contains(int x, int y ) { //int?
        double deltaX = Math.abs( getX() - x );
        double deltaY = Math.abs( getY() - y );

        if( deltaX * deltaX + deltaY * deltaY <= this.getRadius() * this.getRadius() ){
            return this;
        }
        return null;
    }
}
