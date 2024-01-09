/*

 */
import shapes.Circle;
import shapes.Drawable;
import java.awt.Color;
import java.awt.Graphics;

public class Balloon extends Circle implements Drawable
{
    static final int DEFAULT_RADIUS = 25;
    static final int MAX_RADIUS_SIZE = 100;

    public Balloon( double x, double y ) {
        super( DEFAULT_RADIUS );
        super.setLocation( x , y );
    }

    /**
     *
     * @param g
     */
    int red = ( int ) ( Math.random() * 200 );
    int green = ( int ) ( Math.random() * 200 );
    int blue = ( int ) ( Math.random() * 200 );

    Color random = new Color( red, green, blue, 55 );

    @Override
    public void draw( Graphics g ) {

        int tmpx = ( int )this.getX();
        int tmpy = ( int )this.getY();

        g.drawOval( tmpx - this.getRadius() , tmpy - getRadius() , this.getRadius() * 2, this.getRadius() * 2 );
        g.setColor( random );
        g.fillOval( tmpx - this.getRadius() , tmpy - getRadius() , this.getRadius() * 2, this.getRadius() * 2 );
    }

    /**
     *
     */
    public void grow(){
        //grow up to 100 which is maximum size of circle
        if( super.getRadius() <= MAX_RADIUS_SIZE ){
            super.setRadius( this.getRadius() + 1 );
        }
        else {
            this.setRadius( 0 );
            this.setSelected( true );
        }
    }
}
