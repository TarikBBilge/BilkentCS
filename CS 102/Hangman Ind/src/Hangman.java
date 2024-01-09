public class Hangman
{
    //constants
    final private int MAX_ALLOWED_INCORRECT_TRIES = 6;
    //declare variables
    StringBuffer secretWord;
    StringBuffer allLetters;
    String usedLetters;
    StringBuffer knownSoFar;
    int numberOfIncorrectTries;

    //word array
    String[] secretWordArr = { "SOFTWARE", "COLLEGE", "CLASSROOM", "LANGUAGE", "INTERNET", "DATABASE" };

    //constructor
    public Hangman(){
        this.allLetters = new StringBuffer( "A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z" );
        chooseSecretWord();
        numberOfIncorrectTries = 0;
        this.secretWord = secretWord;
        this.usedLetters = "";
        this.knownSoFar = new StringBuffer( "_".repeat( secretWord.length() ) );
    }

    //accessors
    public String getAllLetters(){
        return this.allLetters.toString();
    }
    public String getUsedLetters(){
        return this.usedLetters.toString();
    }
    public int getNumOfIncorrectTries(){
        return this.numberOfIncorrectTries;
    }
    public int getMaxAllowedIncorrectTries(){
        return MAX_ALLOWED_INCORRECT_TRIES;
    }
    public String getKnownSoFar(){ // returns partial word formed with known letters only
        return this.knownSoFar.toString();
    }
    //mutators

    //methods
    public int tryThis( String letter ) { // returns number of occurrences of letter in secretWord
        int numberOfOccurrence = 0;
        for( int i = 0; i < secretWord.length(); i++ ){
            if( Character.toUpperCase( letter.charAt( 0 ) ) == secretWord.charAt( i ) ){
                knownSoFar.setCharAt( i, Character.toUpperCase( letter.charAt( 0 ) ) );
                numberOfOccurrence++;
            }
        }
        return numberOfOccurrence;
    }
    public boolean isGameOver(){
        if( hasLost() || allLetters == secretWord ){
            return true;
        }
        return false;
    }
    public boolean hasLost(){
        if( numberOfIncorrectTries == MAX_ALLOWED_INCORRECT_TRIES ){
            return true;
        }
        return false;
    }
    public void chooseSecretWord( ) { // initially use fixed list, called from constructor
        int words = secretWordArr.length;
        int randWordNum = ( int )( words * Math.random() );
        String secretWord = secretWordArr[ randWordNum ];
    }
}
