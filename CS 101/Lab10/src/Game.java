/*
 * This program generates BlackJack/21 game.
 * Lab 10 Game
 * Author: Tarik Berkan Bilge
 * Date: 06.05.2021
 */
import java.util.Scanner;
public class Game
{
    //data members
    Deck   gameDeck;
    Card[] playerHand,
           dealerHand;
    int    playerCards,
           dealerCards;

    //constructor
    public Game(){
        gameDeck = new Deck();
        playerHand = new Card[11];
        dealerHand = new Card[11];
        playerCards = 0;
        dealerCards = 0;
    }

    //methods
    public String printHand( String p ){
        String str = "";
        //if it is player's hand
        if( p.equals( "player hand" ) ) {
            for (int i = 0; i < playerCards; i++) {
                str = str + playerHand[i] + "\n";
            }
        }
        //if it is player's hand
        else if( p.equals( "dealer hand" ) ) {
            for (int i = 0; i < dealerCards; i++) {
                str = str + dealerHand[i] + "\n";
            }
        }
        return str;
    }

    public int point( String p ){
        int     playerPoint = 0,
                dealerPoint = 0;

        //if it is player's hand
        if( p.equals( "player hand" ) ){
            for( int i = 0; i < playerCards; i++ ){
                playerPoint = playerPoint + playerHand[i].getValue();
            }
            return playerPoint;
        }
        //if it is dealer's hand
        else if( p.equals( "dealer hand" ) ){
            for( int i = 0; i < dealerCards; i++ ){
                dealerPoint = dealerPoint + dealerHand[i].getValue();
            }
        }
        return dealerPoint;
    }

    public boolean determineResult(){
        //if the dealer's point exceed 21 user wins
        if( point( "dealer hand" ) > 21 ){
            return true;
        }
        //if the user's point exceed 21 user loses
        if( point( "player hand" ) > 21 ){
            return false;
        }
        //if the user under 21
        else if( point( "player hand" ) < 21 ){
            //if dealer's point equals 21 user loses
            if( point( "dealer hand" ) == 21 ){
                return false;
            }
            //if dealer's point is between 17 and 21
            else if( point( "dealer hand" ) < 21 && point( "dealer hand" ) >= 17 ){
                //if user's point is smaller than dealer's user loses
                if( point( "player hand" ) < point( "dealer hand" ) ) {
                    return false;
                }
                //if user's point is bigger than dealer's user wins
                else if( point( "player hand" ) > point( "dealer hand" ) ){
                    return true;
                }
                //if user's point equals dealer's user loses
                else{
                    return false;
                }
            }
            //if dealer's point smaller than 17 continue to play
            else if( point( "dealer hand" ) < 17 ){
                play();
            }
        }
        else{   //if player point is 21
            if( playerCards == 2 ) {
                System.out.println("BlackJack!!" + "\n");
            }
        }
        return true;
    }

    public void result(){
        System.out.println( "Dealer hand:" );
        System.out.println( printHand( "dealer hand" ) );
        System.out.println( "Player: " + point( "player hand" ) + " Dealer:" + point( "dealer hand" ) );
        //if user wins
        if( determineResult() ){
            System.out.println( "Congrats - You win!" );
        }
        //if user loses
        else{
            System.out.println( "Sorry - you lose" );
        }
    }

    public void play(){
        int hitstay;

        //if it is the beginning of the game
        if( playerCards == 0 ) {
            playerHand[playerCards] = gameDeck.dealCard();
            playerCards++;
            playerHand[playerCards] = gameDeck.dealCard();
            playerCards++;

            dealerHand[dealerCards] = gameDeck.dealCard();
            dealerCards++;
            dealerHand[dealerCards] = gameDeck.dealCard();
            dealerCards++;
        }
        //if the game has already started
        else if( playerCards > 0 ){
            playerHand[playerCards] = gameDeck.dealCard();
            playerCards++;

            dealerHand[dealerCards] = gameDeck.dealCard();
            dealerCards++;
        }

        //show message to user
        System.out.println( "Your hand:" );
        System.out.println( printHand( "player hand" ) );

        Scanner userIn = new Scanner( System.in );
        System.out.print( "(1)Hit or (2)Stay: " );
        hitstay = userIn.nextInt();

        System.out.println( "Your hand:" );

        //if the user hits
        if( hitstay == 1 ){
            playerHand[playerCards] = gameDeck.dealCard();
            playerCards++;
            System.out.println( printHand( "player hand" ) );
            if( determineResult() ) {
                play();
            }
            else{
                result();
            }
            //if dealer's point is smaller than 17
            if( point( "dealer hand" ) < 17 ){
                dealerHand[dealerCards] = gameDeck.dealCard();
                dealerCards++;
            }
        }
        //if the user stays
        else if( hitstay == 2 ){
            //if dealer's point is smaller than 17
            while( point( "dealer hand" ) < 17 ){
                dealerHand[dealerCards] = gameDeck.dealCard();
                dealerCards++;
            }
        }
        determineResult();
        //if dealer's point is between 17 (includes) and 21
        if( point( "dealer hand" ) >= 17 && 21 >= point( "dealer hand" ) ){
            result();
        }
        //if player's point equals or bigger than 21
        if( point( "player hand") >= 21 ){
            result();
        }
    }
}
