package shapes;

public abstract class Shape implements Locatable, Selectable
{
    double x;
    double y;

    public abstract double getArea();

    @Override
    public double getX() {
        return this.x;
    }

    @Override
    public double getY() {
        return this.y;
    }

    @Override
    public void setLocation( double x, double y ) {
        this.x = x;
        this.y = y;
    }
}