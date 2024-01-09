/*
 * This class has methods for calculator's unary calculation buttons.
 * Author: Tarik Berkan Bilge
 * Date: 17.11.2021
 */

import javax.swing.*;
import java.awt.event.ActionEvent;

public class UnaryCalculationButton extends CalculationButton
{
    //variables


    public UnaryCalculationButton( Operation operation, JTextField number1Field, JTextField number2Field, JLabel result, CountInformer informer ){
        super( operation, number1Field, number2Field , result, informer );

    }

    @Override
    public void actionPerformed( ActionEvent e ) {
        if( number1Field.getText().isEmpty() ){
            JOptionPane.showMessageDialog( null, "ENTER NUMBER TO NUMBER 1 FIELD" );
        }
        else {
            try {
                number1 = Integer.parseInt( number1Field.getText() );
            } catch (Exception error) {
                error.printStackTrace();
            }

            result.setText( "Result: " + operation.calculateResult( number1, 0 ) );

            informer.countUpdated();
        }
    }
}