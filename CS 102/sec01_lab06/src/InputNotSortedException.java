
public class InputNotSortedException extends RuntimeException
{
    public InputNotSortedException(){
        super();
        System.out.println( "Input is not sorted properly" );
    }
}
