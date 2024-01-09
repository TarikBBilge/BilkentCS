import java.util.Scanner;
public class Lab06_Q1
{
    public static long reverseNumber( long cardNo ){

    long    reverse = 0;

    do{
        reverse = reverse * 10;
        reverse = reverse + ( cardNo % 10 );
        cardNo = cardNo / 10;
    } while( cardNo > 0 );
    return (long)reverse;
}

    public static int countDigits( long cardNo ){

        int     temp   = 1,
                length = 0;

        while( temp <= cardNo ){
            length++;
            temp *= 10;
        }
        return length;
    }

    public static int sumDigits( long reverse, int length ){

        long    sum,
                sumEven = 0,
                sumOdd = 0,
                i = 1;

        while( reverse > 0 ){
            if( i % 2 == 0 ){
                sumEven += reverse % 10;
            }
            else{
                if( reverse % 10 < 5 ){
                    sumOdd += ( reverse % 10 ) * 2;
                }
                else{
                    sumOdd += ( reverse % 10 ) * 2 - 9;
                }
            }
            reverse /= 10;
            i++;
        }
        sum = sumEven + sumOdd;
        return (int)sum;
    }

    public static boolean isValidCard( int sum , int checkDigit ){
        if( ( sum + checkDigit ) % 10 == 0 ){
            return true;
        }
        return false;
    }

    public static long generateValidCard(){

        int     digit;

        long    preCardNo = 0,
                cardNo;

        for( int i = 1; i < 10; i++ ){
            digit = (int)( Math.random() * 10 );
            preCardNo = preCardNo * 10 + digit;
        }
        if( isValidCard( sumDigits( reverseNumber((long)Math.floor( preCardNo / 10 )) , countDigits( (long)Math.floor( preCardNo / 10 ) ) ) , (int)preCardNo % 10 ) == false ){
            cardNo = ( preCardNo * 10 ) + 10 - ( sumDigits( reverseNumber( preCardNo ) , countDigits( preCardNo ) ) % 10 );
        }
        else{
            cardNo = preCardNo;
        }
        return (long)cardNo;
    }

    public static void displayMenu(){
        System.out.println( "---------------MENU---------------" );
        System.out.println( "1 - Validate Credit Card Number" );
        System.out.println( "2 - Generate Valid Credit Card Number" );
        System.out.println( "3 - Exit" );
    }

    public static void main( String[] args ){

        int     checkDigit,
                choice;

        long    preCardNumber,
                cardNumber;

        Scanner userIn = new Scanner( System.in );

        do {
            displayMenu();
            //show message to user
            System.out.print( "Enter choice: ");
            choice = userIn.nextInt();

            if (choice == 1) {
                System.out.print("Enter credit card number to validate: ");
                preCardNumber = userIn.nextLong();
                checkDigit = ( (int)preCardNumber % 10);
                cardNumber = (long)preCardNumber / 10;

                System.out.println( "Card number is valid: " + isValidCard( sumDigits( reverseNumber( (long)cardNumber ) , countDigits( (long)cardNumber ) ) , checkDigit ) );
            }
            else if (choice == 2) {
                System.out.println( "Sample valid credit card: " + generateValidCard() );
            }
            else if (choice == 3) {
                System.out.print( "Goodbye!" );
            }
            else {
                System.out.println( "Invalid choice - try again" );
            }
        }
        while( choice != 3 );
    }
}