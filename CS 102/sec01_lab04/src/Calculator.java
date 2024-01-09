/*
 * This is main class for the calculator.
 * Author: Tarik Berkan Bilge
 * Date: 16.11.2021
 */

import javax.swing.*;
import java.awt.*;

public class Calculator extends JFrame
{
    //constructor
    public Calculator(){
        this.setTitle( "Calculator" );
        this.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        CalculatorPanel calculatorPanel = new CalculatorPanel();
        this.add( calculatorPanel );
        this.setPreferredSize( new Dimension( 600, 300 ) );
        this.pack();
        this.setVisible( true );
    }

    public static void main( String[] args ){
        new Calculator();
    }
}
