/*
 * This class is a abstract class for operations to extend.
 * Author: Tarik Berkan Bilge
 * Date: 13.11.2021
 */
public abstract class Operation
{
    protected int called = 0;
    private boolean binary;
    private String name;
    abstract public int calculateResult( int a, int b );

    public Operation( boolean binary, String name ){
        this.binary = binary;
        this.name = name;
    }

    public int getCalled() {
        return called;
    }

    public String getName() {
        return name;
    }
}
