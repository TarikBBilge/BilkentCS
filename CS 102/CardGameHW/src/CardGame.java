//package cardgame;

import java.util.ArrayList;
// Cardgame
// author: Tarik Berkan Bilge
// date: 12/10/2021
public class CardGame
{
    // properties
    Cards             fullPack;
    ArrayList<Player> players;
    ScoreCard         scoreCard;
    Cards[]           cardsOnTable;
    int               roundNo;
    int               turnOfPlayer;

    // constructors
    public CardGame( Player p1, Player p2, Player p3, Player p4 )
    {
        players = new ArrayList<Player>();
        players.add( p1 );
        players.add( p2 );
        players.add( p3 );
        players.add( p4 );
    }

    // methods
    private void updateScores(){
        Card max = new Card( 0 );
        for( int i = 0; i < scoreCard.scores.length - 1; i++ ){
            if ( cardsOnTable[ i ].cards[ getRoundNo() - 1 ].getFaceValue() >= max.getFaceValue() ) {
                max = cardsOnTable[ i ].cards[getRoundNo() - 1];
            }
        }
        for (int i = 0; i < scoreCard.scores.length; i++) {
            if ( cardsOnTable[ i ].cards[ getRoundNo() - 1 ].getFaceValue() == max.getFaceValue() ) {
                scoreCard.update( i, 1 );
            }
        }
    }
    public boolean playTurn( Player p, Card c )
    {
        if( !isTurnOf( p ) || isGameOver() ) {
            return false;
        }
        else{
            cardsOnTable[ getTurnOfPlayerNo() - 1 ].addTopCard( c );
            if( roundNo % 4 == 3 ){
                updateScores();
            }
            if( roundNo < 51 ){
                roundNo++;
            }
        }
        return true;
    }

    public boolean isTurnOf( Player p )
    {
        if( players.get( roundNo % 4 ).getName().equals( p.getName() ) ){
            return true;
        }
        return false;
    }

    public boolean isGameOver()
    {
        if( getRoundNo() == 13 ){ //cardsOnTable
            return true;
        }
        return false;
    }

    public int getScore( int playerNumber )
    {
        return scoreCard.scores[ playerNumber - 1 ];
    }

    public String getName( int playerNumber )
    {
        return players.get( playerNumber - 1 ).getName();
    }

    public int getRoundNo()
    {
        if( roundNo < 52 ){
            return ( roundNo / 4 ) + 1;
        }
        return roundNo / 4;
    }

    public int getTurnOfPlayerNo()
    {
        int i;
        for( i = 0; i < players.size() && !isTurnOf( players.get( i ) ); i++ ){
            //(?)
        }
        return i + 1;
    }

    public Player[] getWinners()
    {
        Player[] winners = new Player[ scoreCard.getWinners().length ];
        for( int i = 0; i < winners.length; i++ ){
            winners[ i ] = players.get( scoreCard.getWinners()[ i ] );
        }
        return winners;
    }

    public void startGame(){
        if( players.size() == 4 ){
            fullPack = new Cards( true );
            fullPack.shuffle();

            for( int i = 0; i < 52; i++ ){
                players.get( i % 4 ).hand.addTopCard( fullPack.getTopCard() );
            }
            scoreCard = new ScoreCard( 4 );

            cardsOnTable = new Cards[ 4 ];
            for( int i = 0; i < 4; i++ ){
                cardsOnTable[ i ] = new Cards( false );
            }
            roundNo = 0;
            turnOfPlayer = 0;
        }
    }

    public String showScoreCard()
    {
        return scoreCard.toString();
    }

}
