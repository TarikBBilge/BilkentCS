package shapes;

import java.util.ArrayList;

public class ShapeContainer
{
    public ArrayList<Shape> shapes = new ArrayList<>();

    public void add( Shape s ){
        if( s != null ) {
            this.shapes.add( s );
        }

    }

    double getArea(){
        double totalArea = 0;

        for( int i = 0; i < this.shapes.size(); i++ ){
            totalArea += this.shapes.get( i ).getArea();
        }
        return totalArea;
    }

    public String toString(){
        String shapeStr = "";
        for( int i = 0; i < this.shapes.size(); i++ ){
            shapeStr += this.shapes.get( i ).toString() + "\n";
        }
        return shapeStr;
    }

    public int size(){
        return shapes.size();
    }

    public int selectAllAt( int x, int y ){
        int selectedNum = 0;

        for( int i = 0; i < this.size(); i++ ){

            if( shapes.get( i ).contains( x, y ) != null ){
                shapes.get( i ).setSelected( true );
                selectedNum++;
            }
        }
        return selectedNum;
    }

    public void removeSelected(){
        for( int i = 0; i < this.size(); i++ ){
            if( this.shapes.get( i ).getSelected() ){
                this.shapes.remove( i );
                i--;
            }
        }
    }

    public Shape contains( int x, int y ){
        for( int i = 0; i < shapes.size(); i++ ){
            Shape s = ( shapes.get( i ) ).contains( x, y );
            if( s == null ){
                continue;
            }
            return s;
        }
        return null;
    }
}