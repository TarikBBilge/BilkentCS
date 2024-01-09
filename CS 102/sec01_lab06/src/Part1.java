/*
 * This class searches elements in an array.
 * Author: Tarik Berkan Bilge
 * Date: 15.12.2021
 */

import java.util.Arrays;

public class Part1 {

    public static void main( String args[] ) {
        int n = 10000;
        int k = 5;
        // Each element of the array is between 0 and 4n
        int[] arr = generateRandomArray( n );

        // Sorting is pre-condition of the search algorithms in this lab
        long start =  System.nanoTime();
        Arrays.sort( arr );


        if( k < 2 ){
            throw new KIsLessThan2Exception();
        }
        // Insert appropriate code segments to calculate execution time

        for( int i = 0; i < arr.length; i++ ){

        }

        // Checking if the method can correctly find already existing elements
        for ( int elem : arr ) {
            int res = 999999999;

            // call the search function and assign it to ``res``
            res = genericSearch( arr, elem, 0, arr.length - 1, k );


            // Generalize the code so that you can experiment with different k values in a single execution
            if ( elem != arr[ res ] ) {
                throw new RuntimeException( "Method works incorrectly (cannot properly locate elements)" );
            }
        }


        // Checking if the method can correctly report absence of elements
        int[] nonExistingElements = {-90, -54, 5 * n + 5, 6 * n};
        for( int elem: nonExistingElements ){
            int res = 999999999;

            // call the search function and assign it to ``res``
            res = genericSearch( arr, elem, 0, arr.length - 1, 5 );

            // Generalize the code so that you can experiment with different k values in a single execution
            if (res != -1) {
                throw new RuntimeException("Method works incorrectly (cannot report absence of elements)");
            }
        }
        long stop =  System.nanoTime();
        System.out.println( stop - start );
    }

    public static int binarySearch(int[] arr, int target, int low, int high ){

        //System.out.println( low + " " + high);
        if( low > high ) {
            return -1;
        }
        int mid = low + ( high - low ) / 2;

        if( arr[ mid ] == target ){
            return mid;
        }

        if ( arr[ mid ] > target ){
            return binarySearch( arr, target, low, mid - 1 ); //?
        }

        return binarySearch( arr, target, mid + 1, high ); //?
    }

    public static int ternarySearch( int[] arr, int target, int low, int high ){

        if( low > high ) {
            return -1;
        }

        int mid1 = low + ( high - low ) / 3;
        int mid2 = low + 2 * ( high - low ) / 3;

        if( arr[ mid1 ] == target ){
            return mid1;
        }

        if( arr[ mid2 ] == target ){
            return mid2;
        }

        if( arr[ mid1 ] > target ){
            return ternarySearch( arr, target, low, mid1 - 1 );
        }

        if( arr[ mid2 ] > target ){
            return ternarySearch( arr, target, mid1 + 1, mid2 - 1 );
        }

        return ternarySearch( arr, target, mid2 + 1, high );
    }

    public static int genericSearch( int[] arr, int target, int low, int high, int k ){

        int mid = 0;
        for( int i = 1; i < k; i++ ){

            if( low > high ) {
                return -1;
            }

            mid = low + ( i * ( high - low ) / k );

            if( arr[ mid ] == target ){
                return mid;
            }

            if( arr[ mid ] > target ){
                return genericSearch( arr, target, low, mid - 1, k );//?
            }
        }
        return genericSearch( arr, target, mid + 1, high, k );//?
    }

    /**
     * YOU SHOULD NOT TOUCH BELOW THIS POINT
     * YOU SHOULD NOT TOUCH BELOW THIS POINT
     * YOU SHOULD NOT TOUCH BELOW THIS POINT
     */

    public static int[] generateRandomArray( int length )
    {
        int[] array = new int[ length ];

        for (int i = 0; i < length; ++i)
        {
            array[i] = (int)(Math.random() * length * 4);
        }

        return array;
    }

}