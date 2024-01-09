/*

 */
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Arrays;

public class Document
{
    String fileName;

    Term terms[] = new Term[ 10000 ];

    //constructor
    public Document( String fileName ){

        this.fileName = fileName;
        this.terms = terms;
    }

    //accessors and mutators
    public String getFileName() {
        return fileName;
    }
    public void setFileName( String fileName ) {
        this.fileName = fileName;
    }

    //methods

    /**
     *
     * @throws FileNotFoundException
     */
    public void processDocument() throws FileNotFoundException {

        File inputFile = new File( getFileName() );

        Scanner in = new Scanner( inputFile ).useDelimiter( "[;,\".:\\s]" );

        int i = 0;
        while( in.hasNext() ){
            if( i == 0 ) {
                String temp = in.next().toLowerCase();
                if ( temp.length() != 0 ) {
                    terms[ i ] = new Term( temp );
                    terms[ i ].incrementCount();
                }
            }

            String temp2 = in.next().toLowerCase();
            i++;
            int j = 0;

            if( temp2.length() != 0 ){
                while( j < i ) {
                    if (!temp2.equals(terms[j].getWord())) {
                        if (j == i - 1) {
                            terms[i] = new Term(temp2);
                            terms[ i ].incrementCount();
                                j = i;
                        }
                        else{
                                j++;
                        }
                    }
                    else if (temp2.equals(terms[j].getWord())) {
                        terms[j].incrementCount();
                        j = i;
                        i--;
                    }
                }
            }
            else{
                i--;
            }
        }
    }

    /**
     *
     * @param word
     * @return
     */
    int getCount( String word ){
        int wordAppear = 0;
        for( int i = 0; i < terms.length; i++ ){
            if( terms[ i ] != null && terms[ i ].getWord().equals( word ) ){
                wordAppear++;
            }
        }
        return wordAppear;
    }

    /**
     *
     * @return
     */
    public Term getMax(){
        Term maxAppearTerm = terms[ 0 ];
        for( int i = 0; i < terms.length; i++ ){
            if( terms[ i ] != null && terms[ i ].getCount() > maxAppearTerm.getCount() ){
                maxAppearTerm = terms[ i ];
            }
        }
        return maxAppearTerm;
    }

    /**
     *
     * @param word
     * @return
     */
    public double getFrequency( String word ){
        int total = 0;
        int count = 0;

        for( int i = 0; i < terms.length; i++ ){
            if( terms[ i ] != null ) {
                total += terms[ i ].getCount();
            }
        }
        for( int i = 0; i < terms.length; i++ ){
            if( terms[ i ] != null ) {
                if( word.equals( terms[ i ].getWord() ) ){
                    count = terms[ i ].getCount();
                }
            }
        }
        double freq = (double) count / total;

        return freq;
    }
}