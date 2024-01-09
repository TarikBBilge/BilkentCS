/*

 */

import java.io.FileNotFoundException;
import java.util.Scanner;

public class DocumentAnalyzer
{

    //methods
    public static int includeTerm( Document[] documents, String word ){
        int includes = 0;
        for( int i = 0; i < documents.length; i++ ){
            if( documents[ i ].getCount( word ) > 0 ){
                includes++;
            }
        }
        return includes;
    }

    public static double calcTfIdf( Document[] documents, Document docu, String word ){
        double tfidf;
        int numberDocs = documents.length;

        tfidf = docu.getFrequency( word ) * Math.log( ( double )  numberDocs / includeTerm( documents, word ) );
        return tfidf;
    }

    //main method
    public static void main( String args[] ){

        Scanner userIn = new Scanner( System.in );

        System.out.println( "Enter the number of documents:" );
        int numDocs = userIn.nextInt();

        Document docs[] = new Document[ numDocs ];

        for( int i = 0; i < numDocs; i++ ){
            System.out.println( "Enter the name of the document " + ( i + 1 ) + ":" );
            String docName = userIn.next();

            docs[ i ] = new Document( docName );
        }

        for( int i = 0; i < numDocs; i++ ){
            try {
                docs[i].processDocument();
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        System.out.println( "Enter an option (enter x to quit): " );
        String option = userIn.next();

        do{
            if( option.equals( "1" ) ){
                System.out.println( "Enter the word which you want to find the frequency:" );
                String word = userIn.next();

                for( int i = 0; i < docs.length; i++ ){
                    System.out.println( "Document " + ( i + 1 ) + "\n word: " + word +
                            "\n term frequency: " + docs[ i ].getFrequency( word ) );
                }
            }
            else if( option.equals( "2" ) ){
                for( int i = 0; i < docs.length; i++ ){
                    System.out.println( "Document " + ( i + 1 ) + "\n word: " +
                            docs[ i ].getMax().getWord() + "\n number of appearances: "
                            + docs[ i ].getMax().getCount() );
                }
            }
            else if( option.equals( "3" ) ){
                System.out.println( "Enter the word which you want to calculate tf-idf:" );
                String word = userIn.next();

                for( int i = 0; i < docs.length; i++ ){
                    System.out.println( "Document " + ( i + 1 ) + "\n word: " + word +
                            "\n tf-idf: " + calcTfIdf( docs, docs[ i ], word ) );
                }
            }
            System.out.println( "Enter an option (enter x to quit): " );
            option = userIn.next();
        }while( ( !option.equals( "x" ) ) );
    }
}
