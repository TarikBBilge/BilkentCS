import java.io.FileNotFoundException;
import java.util.Scanner;

public class TestTerms
{
    public static void main( String args[] ){
        Scanner userIn = new Scanner( System.in );

        System.out.println( "Enter the name of the document:" );
        String docName = userIn.next();

        Document doc = new Document( docName );

        try {
            doc.processDocument();
        } catch ( FileNotFoundException e ) {
            e.printStackTrace();
        }

        for( int i = 0; i < doc.terms.length; i++ ){
            if( doc.terms[ i ] != null ) {
                System.out.println(doc.terms[i].getWord() + " " + doc.terms[ i ].getCount() );
            }
        }
    }
}
