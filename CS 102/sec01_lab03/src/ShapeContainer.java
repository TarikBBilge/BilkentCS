import shapes.Shape;

import java.util.ArrayList;

public class ShapeContainer
{
    ArrayList<Shape> shapes = new ArrayList<>();

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

    int size(){
        return shapes.size();
    }

    int selectAllAt( int x, int y ){
        int selectedNum = 0;
        for( int i = 0; i < this.size(); i++ ){
            this.shapes.get( i ).contains( x, y );

            if( this.shapes.get( i ) == null ){
                i++;
            }
            else{
                this.shapes.get( i ).setSelected( true );
                selectedNum++;
            }
        }
        return selectedNum;
    }

    void removeSelected(){
        for( int i = 0; i < this.size(); i++ ){
            if( this.shapes.get( i ).getSelected() ){
                this.shapes.remove( i );
                i--;
            }
        }
    }

    Shape contains( int x, int y ){
        for( int i = 0; i < this.size(); i++ ){
            this.shapes.get( i ).contains( x, y );
            if( this.shapes.get( i ) == null ){
                i++;
            }
            return this.shapes.get( i );
        }
        return null;
    }
}