/*
 *This program prints some area's width and percentages of other areas.
 * CS101 Lab01 Question 3
 * @author Tarik Berkan Bilge
 * @date   02/09/2021
 */
public class Lab01_Q3
{
    public static void main( String[] args )
    {
        //naming
        final long THE_TOTAL_AREA_OF_EARTH = 510072000L;
        final long THE_TOTAL_AREA_OF_TURKEY = 783562;

        //calculations
        final double LAND_AREA_IN_EARTH = ( THE_TOTAL_AREA_OF_EARTH * 29.2/100 );
        final double WATER_AREA_IN_EARTH = ( THE_TOTAL_AREA_OF_EARTH - THE_TOTAL_AREA_OF_EARTH * 29.2 / 100 );
        final long LAND_AREA_IN_TURKEY = ( THE_TOTAL_AREA_OF_TURKEY - THE_TOTAL_AREA_OF_TURKEY * 13 / 1000 );
        final long WATER_AREA_IN_TURKEY = ( THE_TOTAL_AREA_OF_TURKEY * 13 / 1000 );
        final double TURKEY_LAND_AREA_PERCENTAGE_OF_EARTHS = ( LAND_AREA_IN_TURKEY / LAND_AREA_IN_EARTH * 100 );
        final double TURKEY_WATER_AREA_PERCENTAGE_OF_EARTHS = ( WATER_AREA_IN_TURKEY / WATER_AREA_IN_EARTH * 100 );

        //answers
        System.out.println( "Earth has " + (long)LAND_AREA_IN_EARTH + "km² dry land and " + (long)WATER_AREA_IN_EARTH + "km² water." );
        System.out.println( "Turkey has " + LAND_AREA_IN_TURKEY + "km² dry land and " + WATER_AREA_IN_TURKEY + "km² water." );
        System.out.println( "Turkey has " + TURKEY_LAND_AREA_PERCENTAGE_OF_EARTHS + " percent of the Earth's dry land." );
        System.out.println( "And " + TURKEY_WATER_AREA_PERCENTAGE_OF_EARTHS + " percent of the Earth's water." );
    }

}
