/*
 * This class initializes panel for the calculator.
 * Author: Tarik Berkan Bilge
 * Date: 16.11.2021
 */
import javax.swing.*;
import java.awt.*;

public class CalculatorPanel extends JPanel implements CountInformer
{
    //
    private JTextField  number1Field = new JTextField(),
                        number2Field = new JTextField();

    private JLabel      result,
                        additionCount,
                        subtractionCount,
                        multiplicationCount,
                        divisionCount,
                        squareCount,
                        squareRootCount,
                        log10Count,
                        cubeRootCount;

    Operation[] operations = new Operation[ 8 ];
    JLabel[] operationLabels = new JLabel[ 8 ];

    //constructor
    public CalculatorPanel(){
         result = new JLabel( "Result:" );

         additionCount = new JLabel( "Addition:" );
         subtractionCount = new JLabel( "Subtraction:" );
         multiplicationCount = new JLabel( "Multiplication:" );
         divisionCount = new JLabel( "Division:" );

         squareCount = new JLabel( "Square:" );
         squareRootCount = new JLabel( "Square Root:" );
         log10Count = new JLabel( "Log10:" );
         cubeRootCount = new JLabel( "Cube Root:" );

         this.number1Field.setPreferredSize( new Dimension( 80,20 ) );
         this.number2Field.setPreferredSize( new Dimension( 80,20 ) );
        this.number1Field.setText( "Number 1" );
        this.number2Field.setText( "Number 2" );
        this.add( number1Field );
        this.add( number2Field );
        this.add( result );

        //binaries
        Operation add = new Addition( true, "Add" );
        Operation subtract = new Subtraction( true, "Subtract" );
        Operation multiply = new Multiplication( true, "Multiply" );
        Operation divide = new Division( true, "Divide" );

        CalculationButton addButton = new CalculationButton( add, number1Field, number2Field, result, this );
        CalculationButton subtractButton = new CalculationButton( subtract, number1Field, number2Field, result, this );
        CalculationButton multiplyButton = new CalculationButton( multiply, number1Field, number2Field, result, this );
        CalculationButton divideButton = new CalculationButton( divide, number1Field, number2Field, result, this );

        addButton.setText( "Add" );
        subtractButton.setText( "Subtract" );
        multiplyButton.setText( "Multiply" );
        divideButton.setText( "Divide" );

        this.add( addButton );
        this.add( subtractButton );
        this.add( multiplyButton );
        this.add( divideButton );

        //unaries
        Operation square = new Square( false, "Square" );
        Operation squareRoot = new SquareRoot( false, "SquareRoot" );
        Operation log10 = new Log10( false, "Log10" );
        Operation cubeRoot = new CubeRoot( false, "CubeRoot" );

        CalculationButton squareButton = new UnaryCalculationButton( square, number1Field, number2Field, result, this );
        CalculationButton squareRootButton = new UnaryCalculationButton( squareRoot, number1Field, number2Field, result, this );
        CalculationButton log10Button = new UnaryCalculationButton( log10, number1Field, number2Field, result, this );
        CalculationButton cubeRootButton = new UnaryCalculationButton( cubeRoot, number1Field, number2Field, result, this );

        squareButton.setText( "Square" );
        squareRootButton.setText( "SquareRoot" );
        log10Button.setText( "Log10" );
        cubeRootButton.setText( "CubeRoot" );

        this.add( squareButton ).setBackground( Color.RED );
        this.add( squareRootButton ).setBackground( Color.RED );
        this.add( log10Button ).setBackground( Color.RED );
        this.add( cubeRootButton ).setBackground( Color.RED );

        //counts display
        this.add( additionCount );
        this.add( subtractionCount );
        this.add( multiplicationCount );
        this.add( divisionCount );

        this.add( squareCount );
        this.add( squareRootCount );
        this.add( log10Count );
        this.add( cubeRootCount );

        //operations array
        operations[ 0 ] = add;
        operations[ 1 ] = subtract;
        operations[ 2 ] = multiply;
        operations[ 3 ] = divide;
        operations[ 4 ] = square;
        operations[ 5 ] = squareRoot;
        operations[ 6 ] = log10;
        operations[ 7 ] = cubeRoot;

        //operation labels array
        operationLabels[ 0 ] = additionCount;
        operationLabels[ 1 ] = subtractionCount;
        operationLabels[ 2 ] = multiplicationCount;
        operationLabels[ 3 ] = divisionCount;
        operationLabels[ 4 ] = squareCount;
        operationLabels[ 5 ] = squareRootCount;
        operationLabels[ 6 ] = log10Count;
        operationLabels[ 7 ] = cubeRootCount;
    }

    /**
     * This method calculates how many times the operation called and displays it.
     */
    void calculateAndUpdateCountMessage(){
        for( int i = 0; i < operationLabels.length; i++ ){
            operationLabels[ i ].setText( operations[ i ].getName() + ": " + operations[ i ].getCalled() );
        }
    }

    /**
     * This method overrides CountInformer interface's countUpdated method to update the operations' call counts.
     */
    @Override
    public void countUpdated() {
        this.calculateAndUpdateCountMessage();
    }
}
