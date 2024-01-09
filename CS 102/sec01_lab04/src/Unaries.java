/*
 * This class has sub binary operation classes.
 * Author: Tarik Berkan Bilge
 * Date: 13.11.2021
 */

    class Square extends Operation
    {
        public Square( boolean binary, String name ) {
            super( binary, name );
        }

        /**
         *
         * @param a
         * @param b
         * @return
         */
        @Override
        public int calculateResult( int a, int b ) {
            called++;
            return a * a;
        }
    }

    class SquareRoot extends Operation
    {
        public SquareRoot( boolean binary, String name ) {
            super( binary, name );
        }

        /**
         *
         * @param a
         * @param b
         * @return
         */
        @Override
        public int calculateResult( int a, int b ) {
            called++;
            return ( int ) Math.sqrt( a );
        }
    }

    class Log10 extends Operation
    {
        public Log10( boolean binary, String name ) {
            super( binary, name );
        }

        /**
         *
         * @param a
         * @param b
         * @return
         */
        @Override
        public int calculateResult( int a, int b ) {
            called++;
            return ( int ) Math.log10( a );
        }
    }

    class CubeRoot extends Operation
    {
        public CubeRoot( boolean binary, String name ) {
            super( binary, name);
        }

        /**
         *
         * @param a
         * @param b
         * @return
         */
        @Override
        public int calculateResult( int a, int b ) {
            called++;
            return ( int ) java.lang.Math.cbrt( a );
        }
    }
