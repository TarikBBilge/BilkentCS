/*
 * This class has sub binary operation classes.
 * Author: Tarik Berkan Bilge
 * Date: 13.11.2021
 */

    class Addition extends Operation
    {
        public Addition( boolean binary, String name ) {
            super( binary, name );
        }

        /**
         * This method calculates sum of two integers
         * @param a first integer
         * @param b second integer
         * @return sum
         */
        @Override
        public int calculateResult( int a, int b ) {
            called++;
            return a + b;
        }
    }

    class Subtraction extends Operation
    {
        public Subtraction( boolean binary, String name ) {
            super( binary, name );
        }

        /**
         * This method calculates difference between two numbers
         * @param a first integer
         * @param b second integer
         * @return difference
         */
        @Override
        public int calculateResult( int a, int b ) {
            called++;
            return a - b;
        }
    }

    class Multiplication extends Operation
    {
        public Multiplication( boolean binary, String name ) {
            super( binary, name );
        }

        /**
         * This methods calculates multiplication of two integers
         * @param a first integer
         * @param b second integer
         * @return multiplication
         */
        @Override
        public int calculateResult( int a, int b ) {
            called++;
            return a * b;
        }
    }

    class Division extends Operation
    {
        public Division( boolean binary, String name ) {
            super( binary, name );
        }

        /**
         * This method calculates division of two integers
         * @param a first integer
         * @param b second integer
         * @return division
         */
        @Override
        public int calculateResult( int a, int b ) {
            called++;
            return a / b;
        }
    }

