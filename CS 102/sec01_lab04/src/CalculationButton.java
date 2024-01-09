/*
 * This class has methods for calculator's binary calculation buttons.
 * Author: Tarik Berkan Bilge
 * Date: 15.11.2021
 */
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalculationButton extends JButton implements ActionListener
{
    //variables
    protected Operation operation;

    protected JTextField  number1Field,
                        number2Field;

    protected JLabel      result;

    protected CountInformer informer;

    int number1;
    int number2;

    //constructor
    public CalculationButton( Operation operation, JTextField number1Field, JTextField number2Field, JLabel result, CountInformer informer ){
        this.operation = operation;
        this.number1Field = number1Field;
        this.number2Field = number2Field;
        this.result = result;
        this.informer = informer;
        this.addActionListener( this );
    }

    /**
     * This method takes integer from text fields and displays the result of an operation.
     * @param e represents which button pressed
     */
    @Override
    public void actionPerformed( ActionEvent e ) {
        if( ! number1Field.getText().isEmpty() && ! number2Field.getText().isEmpty() ) {
            try {
                number1 = Integer.parseInt(number1Field.getText());
                number2 = Integer.parseInt(number2Field.getText());
            } catch (Exception error) {
                error.printStackTrace();
            }

            result.setText("Result: " + operation.calculateResult(number1, number2));

            informer.countUpdated();
        }
        else{
            JOptionPane.showMessageDialog( null, "ENTER NUMBER TO NUMBER FIELDS" );
        }
    }
}