//package cardgame;

/**
 * Card - a single playing card
 * @author Tarik Berkan Bilge
 * @version 10/10/2021
 */
public class Card
{
    final String[] SUITS = { "Hearts", "Diamonds", "Spades", "Clubs" };
    final String[] FACES = { "A", "2", "3", "4", "5",
            "6", "7", "8", "9", "10",
            "J", "Q", "K"};

    final int NOOFCARDSINSUIT = 13;

    // properties
    int  cardNo;

    // constructors
    public Card( int faceValue, int suit )
    {
        cardNo = faceValue + suit * NOOFCARDSINSUIT;
    }

    public Card( int cardNumber )
    {
        cardNo = cardNumber;
    }

    public int getFaceValue()
    {
        return cardNo % NOOFCARDSINSUIT;
    }

    public int getSuit()
    {
        return cardNo / NOOFCARDSINSUIT;
    }

    public String toString()
    {
        return FACES[ getFaceValue() ] + " of " + SUITS[ getSuit() ];
    }

    public boolean equals( Card c )
    {
        if( getFaceValue() == c.getFaceValue() && getSuit() == c.getSuit() ){
            return true;
        }
        return false;
    }

    public int compareTo( Card c )
    {
        if( getFaceValue() == c.getFaceValue() ) {
            return 0;
        }
        else if( getFaceValue() > c.getFaceValue() ){
            return 1;
        }
        return 2;
    }
}
