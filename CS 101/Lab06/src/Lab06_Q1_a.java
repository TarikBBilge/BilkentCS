/*
* This program checks and generates valid credit card.
* Lab06 Question 1
* Author: Tarik Berkan Bilge
* Date: 18.03.2021
 */
/**import java.util.Scanner;
public class Lab06_Q1_a {
    //dropLastDigit method to drop the last digit as wanted in Luhn Algorithm
    public static long dropLastDigit(long number){
        number = number / 10;
        return number;
    }
    //reverseNumber method to reverse the number as wanted in Luhn Algorithm
    public static long reverseNumber(long number){
        number = dropLastDigit(number);
        long result = 0;
//operations like palindrom numbers
        while(number != 0){
            result = result * 10 + number % 10;
            number = number / 10;
        }
        return result;
    }
    //countDigits method to count every digit to know how many digits that number has
    static int countDigits(long number){
        number = reverseNumber(number);
        int count = 0;
        while (number != 0){
            number = number / 10;
            count++;
        }
        return count;
    }
    static long sumDigits(long number) {
        number = dropLastDigit(number);
        long sumOdd = 0, sumEven= 0, c = 1;
//c is checker in this while
        while (number != 0) {
//if statement for odd numbers
            if (c % 2 != 0) {
//operations for numbers at odd places as wanted in Luhn Algorithm
                if ((2 * (number % 10)) > 9) {
                    sumOdd = sumOdd + (2 * (number % 10)) - 9;
                }
                else {
                    sumOdd = sumOdd + (2 * (number % 10));
                }
            }
//else statement for even numbers (no operation wanted for even numbers in Luhn Algorithm)
            else {
                sumEven = sumEven + (number % 10);
            }
//number's type is long, so we can check every digit by dividing 10 (shortening 1 digit every step to check every digit until number not equal to 0)
            number = number / 10;
            c++;
        }
        long sumTotal = sumEven + sumOdd;
        return sumTotal;
    }
    //isValidCard method to print true or false by checking the credit card number as wanted in Luhn Algorithm
    static boolean isValidCard(long number) {
//if the number is multiple of 10 return true, if not return false
        if (((number % 10) + sumDigits(number)) % 10 == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    static long generateValidCard( long number ){
        long randNum;

        do{
            double a = Math.random();
            if( a > 0.5 ){
                randNum = (long)( a * 1E15 );
            }
            else{

            }
        }
    }

    public static void displayMenu() {
        System.out.println("---------------MENU---------------");
        System.out.println("1 - Validate Credit Card Number");
        System.out.println("2 - Generate Valid Credit Card Number");
        System.out.println("3 - Exit");
    }

    public static void main(String[] args) {

        int checkDigit,
                choice;

        long cardNumber;

        Scanner userIn = new Scanner(System.in);

        do {
            displayMenu();
            //show message to user
            System.out.print("Enter choice: ");
            choice = userIn.nextInt();

            if (choice == 1) {
                System.out.print("Enter credit card number to validate: ");
                cardNumber = userIn.nextLong();
                checkDigit = (int) (cardNumber % 10);
                cardNumber = cardNumber / 10;

                System.out.println("Card number is valid: " + isValidCard(sumDigits(reverseNumber(cardNumber), countDigits(cardNumber)), checkDigit));
            }
            else if (choice == 2) {
                System.out.println("Sample valid credit card: " + generateValidCard());
            }
            else if (choice == 3) {
                System.out.print("Goodbye!");
            }
            else {
                System.out.println("Invalid choice - try again");
            }
        } while (choice != 3);
    }
}*/