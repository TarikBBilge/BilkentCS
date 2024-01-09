/*
 * This program generates a deck and shuffles it.
 * Lab 10 Deck
 * Author: Tarik Berkan Bilge
 * Date: 04.05.2021
 */
import java.util.Random;
public class Deck
{
    //data members
    public int topCard;
    public static Card[] deck = new Card[52];

    //constructor
    public Deck(){
        initialize();
        shuffle();
        topCard = 0;
    }

    //methods
    public void initialize(){
        int num = 0;
        for( int i = 1; i <= 13; i++ ){
            for( int j = 1; j <= 4; j++ ){
                deck[num] = new Card( j, i );
                num++;
            }
        }
    }

    public Card[] shuffle(){
        Random shuffle = new Random();

        for( int i = 0; i < deck.length; i++ ){
            int randomIndexToSwap = shuffle.nextInt( deck.length );
            Card temp = deck[randomIndexToSwap];
            deck[randomIndexToSwap] = deck[i];
            deck[i] = temp;
        }
        return deck;
    }
    public Card dealCard(){
        topCard++;
        return deck[topCard -1];
    }
    public String toString(){
        String  allCards = "";
        for( int i = 0; i < 52; i++ ){
            allCards = allCards + deck[i] + "\n";
        }
        return allCards;
    }
}
