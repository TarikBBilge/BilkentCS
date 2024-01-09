/*

 */

import java.awt.*;
import java.io.PrintStream;
import javax.swing.JFrame;

public class Lab03_Part2 extends JFrame
{
    public Lab03_Part2(){
        this.setTitle( "Lab03 Balloons Game" );
        this.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        BalloonsGamePanel balloonsGamePanel = new BalloonsGamePanel();
        this.add( balloonsGamePanel );
        this.pack();
        this.setVisible( true );
    }
    public static void main( String[] args ){
        new Lab03_Part2();
    }
}
