/*
 * This program executes Project, Department, Employee classes.
 * Lab 08 Employee Application
 * Author: Tarik Berkan Bilge
 * Date: 15.04.2021
 */
public class EmployeeApp
{
    public static void main( String[] args ){
        //project
        Project project = new Project( "SunMarkets POS Implementation", 315, 320, 22 );

        //employees
        System.out.println( "Employees:");
        Employee employee1 = new Employee( "Karakus, Zana", 215.0, project, "Information Technology", "IT" );
        Employee employee2 = new Employee( "Rocca, Denis", 175.0, project, "Human Resources", "HR" );
        Employee employee3 = new Employee( "Anders, Jamie", 275.0, project, "Human Resources", "HR" );
        Employee employee4 = employee1;

        //print out employees
        System.out.println( employee1 );
        System.out.println( employee2 );
        System.out.println( employee3 );
        System.out.println( employee4 );
        System.out.println( "--------- end employee list ----------" );

        int i = 1;

        //compare employee departments
        if( employee1.getDepartment().equals( employee2.getDepartment() ) ){
            System.out.println( "_____________________\n" + "Employees with Matching Departments" + " (" + i + ")\n" );
            System.out.println( employee1 );
            System.out.println( employee2 );
            i++;
        }
        if( employee1.getDepartment().equals( employee3.getDepartment() ) ){
            System.out.println( "_____________________\n" + "Employees with Matching Departments" + " (" + i + ")\n" );
            System.out.println( employee1 );
            System.out.println( employee3 );
            System.out.println( i );
            i++;
        }
        if( employee1.getDepartment().equals( employee4.getDepartment() ) ){
            System.out.println( "_____________________\n" + "Employees with Matching Departments" + " (" + i + ")\n" );
            System.out.println( employee1 );
            System.out.println( employee4 );
            i++;
        }
        if( employee2.getDepartment().equals( employee3.getDepartment() ) ){
            System.out.println( "_____________________\n" + "Employees with Matching Departments" + " (" + i + ")\n" );
            System.out.println( employee2 );
            System.out.println( employee3 );
            i++;
        }
        if( employee2.getDepartment().equals( employee4.getDepartment() ) ){
            System.out.println( "_____________________\n" + "Employees with Matching Departments" + " (" + i + ")\n" );
            System.out.println( employee2 );
            System.out.println( employee4 );
            i++;
        }
        if( employee3.getDepartment().equals( employee4.getDepartment() ) ){
            System.out.println( "_____________________\n" + "Employees with Matching Departments" + " (" + i + ")\n" );
            System.out.println( employee3 );
            System.out.println( employee4 );
            i++;
        }
    }
}
