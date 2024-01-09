/*

 */

import shapes.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;



public class BalloonsGamePanel extends JPanel
{
    //variables
    final int FRAME_WIDTH = 900;
    final int FRAME_HEIGHT = 800;
    final int INITIAL_BALLOONS = 25;
    final int MAXIMUM_TIME = 500;
    ShapeContainer balloons;
    Timer timer;
    int elapsedTime;
    int points;
    JLabel pointsLabel = new JLabel();
    MouseListener pin;

    //constructor
    public BalloonsGamePanel(){
        this.setBackground( Color.yellow );
        this.add( pointsLabel );
        this.setPreferredSize( new Dimension( FRAME_WIDTH, FRAME_HEIGHT ) );
        this.timer = new Timer( 100, new GameListener() );
        this.pin = new Pin();
        this.initiateGame();
    }

    //methods

    /**
     * This method initiates the balloons game
     */
    void initiateGame(){
        this.points = 0;
        this.elapsedTime = 0;
        this.pointsLabel.setText( "Points: " + this.points );
        this.balloons = new ShapeContainer();
        this.putRandBalloons( INITIAL_BALLOONS, FRAME_WIDTH, FRAME_HEIGHT );
        this.addMouseListener( this.pin );
        this.timer.start();
    }

    /**
     *
     * @param balloons balloons number on screen
     * @param width
     * @param height
     */
    void putRandBalloons( int balloons, int width, int height ){
        for( int i = 0; i < balloons; i++ ){
            double x = Math.random() * width;
            double y = Math.random() * height;

            Balloon randBalloon = new Balloon( x, y );

            this.balloons.add( randBalloon );
        }
    }

    /**
     *
     * @param g
     */
    //@Override
    public void paintComponent( Graphics g ){
        super.paintComponent( g );

        for( int i = 0; i < BalloonsGamePanel.this.balloons.size(); i++ ){
            ( ( Balloon )balloons.shapes.get( i ) ).draw( g );
        }

    }

    class Pin extends MouseAdapter
    {
        private Pin(){
        }

        /**
         *
         * @param click
         */
        @Override
        public void mousePressed( MouseEvent click ){
            int burstCount = balloons.selectAllAt( click.getX(), click.getY() );

            if( burstCount >= 2 ){
                points += burstCount;
                pointsLabel.setText( "Points: " + points );
            }
        }
    }

    class GameListener implements ActionListener
    {
        private GameListener(){
        }

        /**
         *
         * @param e
         */
        @Override
        public void actionPerformed( ActionEvent e ) {
            for( int i = 0; i < balloons.size(); i++ ){
                if( ( balloons.shapes.get( i ) ) != null ) {
                    ( ( Balloon )balloons.shapes.get( i ) ).grow();
                }
            }
            balloons.removeSelected();
            repaint();
            if( balloons.size() < 15 ){
                putRandBalloons( ( 15 - balloons.size() ),
                        FRAME_WIDTH, FRAME_HEIGHT );
            }

            elapsedTime++;

            if( elapsedTime >= MAXIMUM_TIME ){
                BalloonsGamePanel.this.removeMouseListener( pin );

                int selection = JOptionPane.showConfirmDialog( null,
                        "Play again?", null , JOptionPane.YES_OPTION, JOptionPane.YES_NO_OPTION  );

                if( selection == JOptionPane.YES_OPTION ){
                    initiateGame();
                }
                else{
                    timer.stop();
                }
            }
        }
    }
}