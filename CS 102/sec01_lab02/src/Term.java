/*

 */
public class Term
{
    private String word;
    private int   count;

    //constructor
    public Term( String word ){
        this.word = word;
        this.count = 0;
    }

    //accessors and mutators
    public String getWord(){
        return word;
    }
    public void setWord( String word ){
        this.word = word;
    }
    public int getCount(){
        return this.count;
    }

    //methods

    /**
     *
     */
    void incrementCount(){
        this.count++;
    }
}
