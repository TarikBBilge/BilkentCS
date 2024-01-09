/*
 * This program executes Game class and plays to the user.
 * Lab 10 GameApp
 * Author: Tarik Berkan Bilge
 * Date: 06.05.2021
 */
import java.util.Scanner;
public class GameApp
{
    public static void main( String[] args ){

        Scanner userIn = new Scanner( System.in );

        String  answ;
        //play game as long as the user says yes
        do{
            Game blackjack = new Game();
            blackjack.play();
            System.out.print( "Play again? (y/n): ");
            answ = userIn.next();
        }while( answ.equals( "y" ) );
        //if the user says no finish the game
        if( answ.equals( "n" ) ){
            System.out.print( "Thanks for playing - Goodbye!" );
        }
    }
}
