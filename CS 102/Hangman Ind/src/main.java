import java.util.Scanner;
public class main
{
    public static void main( String[] args ){
        Scanner userIn = new Scanner( System.in );
        String letter;
        Hangman hangGame = new Hangman();
        do{
            System.out.println( "The word you are searching is: " + hangGame.getKnownSoFar() );
            System.out.println( "Remaining incorrect tries are/is: " + ( hangGame.getMaxAllowedIncorrectTries() - hangGame.getNumOfIncorrectTries() ) );
            System.out.println( "Letters to be chosen " + hangGame.getAllLetters());
            System.out.println( "Used letters:" + hangGame.getUsedLetters() );
            System.out.println( "Choose a letter: " );
            letter = userIn.next();
            if( hangGame.tryThis( letter ) == 0 ) {
                hangGame.numberOfIncorrectTries++;
            }
            if( hangGame.hasLost() ){
                System.out.println( "You lost! The word is :" + hangGame.secretWord );
            }
            else{
                System.out.println( "You win! The word you found id :" + hangGame.secretWord );
            }
        } while( !hangGame.isGameOver() );
    }
}
