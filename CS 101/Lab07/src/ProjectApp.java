/*
 *This program executes Project methods.
 * Lab 07 Assignment
 * Author: Tarik Berkan Bilge
 * Date: 08.04.2021
 */
public class ProjectApp
{
    public static void main( String[] args ){

        Project p1 = new Project( "ArcTech Business Solution" , 11520 , 215 , 48 );
        Project p2 = new Project( "SunMarkets POS Implementation", 315, 320, 22 );
        Project p3 = new Project( "HealthTech Hospital" , 0 , 0 , 0 );

        System.out.println( p1 );
        System.out.println( p2 );
        p3.deactivateProject();
        System.out.println( p3 );

        //if second project has greater cost
        if( p2.compareProjects( p1 ) == 1 ){
            System.out.println( "p2 is greater than p1" );
        }
        //if first project has greater cost
        else if( p2.compareProjects( p1 ) == -1 ){
            System.out.println( "p2 is smaller than p1" );
        }
        //if projects have same cost
        else{
            System.out.println( "p2 has same cost with p1" );
        }

        p1.setPersonHours( 8000 );
        p1.setProjectWeeks( 35 );
        p1.setRatePerHour( 237 );

        p3.setProjectType();

        System.out.println( p1 );
        System.out.println( p2 );
        System.out.println( p3 );
    }
}
