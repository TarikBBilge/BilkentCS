package shapes;
/*
 *
 *
 * Author: Tarik Berkan Bilge
 * Date: 13/10/2021
 */

public class Circle extends Shape
{
    //variables
    public int radius;
    boolean isSelected;
    double x;
    double y;

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
    public boolean getSelected() {
        return this.isSelected;
    }

    @Override
    public void setSelected( boolean selected ) {
        this.isSelected = selected;
    }

    @Override
    public double getX() {
        return this.x;
    }

    @Override
    public double getY() {

        return this.y;
    }

    @Override
    public Shape contains( int x, int y ) { //int?
        double deltaX = Math.abs( getX() - x );
        double deltaY = Math.abs( getY() - y );

        if( ( deltaX * deltaX ) + ( deltaY * deltaY ) <= this.getRadius() * this.getRadius() ){
            return new Circle( getRadius() ) ;
        }
        return null;
    }

    @Override
    public void setLocation( double x, double y ) {
        this.x = x;
        this.y = y;
    }
}
