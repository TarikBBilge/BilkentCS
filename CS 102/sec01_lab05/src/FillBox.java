/*
 * This program creates 2d array in terms of user inputs.
 * Author: Tarik Berkan Bilge
 * Date: 01.12.2021
 */

import java.util.Scanner;

public class FillBox
{
    /**
     * This method creates 2d array
     * @param row is height of rectangle
     * @param column is width of rectangle
     * @return rectangle which is 2d array
     */
    static char[][] createArray( int row, int column ){
        char[][] box = new char[ row ][ column ];

        for( int i = 0; i < row; i++ ){
            if( i == 0 || i == row - 1 ){
                for( int j = 0; j < column; j++ ) {
                    box[i][j] = '#';
                }
            }
            else{
                box[ i ][ 0 ] = '#';
                for( int j = 1; j < column - 1; j++ ){
                    box[ i ][ j ] = ' ';
                }
                box[ i ][ column - 1 ] = '#';
            }
        }
        return box;
    }

    /**
     * This method prints array rectangle.
     * @param array is rectangle array
     */
    static void printArray( char[][] array ){
        for( int i = 0; i < array.length; i++ ) {
            System.out.println( array[ i ] );
        }
    }

    /**
     * This method fills rectangle array box.
     * @param array is rectangle array
     * @param row is height of array
     * @param column is width of array
     * @param ch is character which fills space
     */
    static void fillBox( char[][] array, int row, int column, char ch ){

        if( array[ row - 1 ][ column - 1 ] == ' ' ){
            array[ row - 1 ][ column - 1 ] = ch;

            fillBox( array, row, column - 1, ch );
            fillBox( array, row - 1, column, ch );

        }

    }

    /**
     * This method draws fractal figures in square
     * @param square is rectangle array
     * @param x is x offset
     * @param y is y offset
     * @param size edge of square
     */
    static void drawFigure( char[][] square, int x, int y, int size ){

        if( size > 7 ){
            for( int i = 0; i < size; i++ ){
                square[ x + size / 2 ][ i + y ] = '#';
            }
            for( int i = 0; i < size; i++ ){
                square[ i + x ][ y + size / 2 ] = '#';
            }
            drawFigure( square, x, y, size / 2 );
            drawFigure( square, x + size / 2, y, size / 2 );
            drawFigure( square, x + size / 2, y + size / 2, size / 2 );
            drawFigure( square, x, y + size / 2, size / 2 );
        }
        else{
            fillBox( square, size + x, size + y, '*' );
        }

    }

    static char ch;

    public static void main( String[] args ){

        Scanner userIn = new Scanner( System.in );

        System.out.println( "Row: ");
        int rowU = userIn.nextInt();

        System.out.println( "Column: ");
        int columnU = userIn.nextInt();

        System.out.println( "Character: ");
        ch = userIn.next().charAt( 0 );


        char[][] array = createArray( rowU,columnU );
        char[][] array2 = createArray( 25, 25 );

        printArray( array );

        fillBox( array, rowU - 1, columnU - 1, ch );
        printArray( array );

        drawFigure( array2, 0, 0, 25 );
        printArray( array2 );
    }
}
