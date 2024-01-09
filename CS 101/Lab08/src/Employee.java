/*
 * This program provides methods to Employee Application.
 * Lab 08 Employee
 * Author: Tarik Berkan Bilge
 * Date: 15.04.2021
 */
public class Employee
{
    //constants
    private static final int WORKING_DAYS = 261;

    //properties
    private String      employeeName;
    private double      dailyRate;
    private Department  department;
    private Project     project;

    //constructors
    public Employee( String name, double rate, Project project , String deptName, String deptCode ){
        employeeName = name;
        dailyRate = rate;
        this.project = project;
        department = new Department( deptName, deptCode );
    }
    public Employee( Employee eCopy ){
        new Employee( eCopy.employeeName, eCopy.dailyRate, eCopy.project, eCopy.getDepartment().getDeptName(), eCopy.getDepartment().getDeptCode() );
    }

    //methods
    public String getEmployeeName(){
        return  employeeName;
    }

    public void setEmployeeName( String employeeName ){
        this.employeeName = employeeName;
    }

    public double getDailyRate() {
        return dailyRate;
    }

    public void setDailyRate( double dailyRate ) {
        this.dailyRate = dailyRate;
    }

    public Department getDepartment() {
        return department;
    }

    public void setDepartment( Department department ) {
        this.department = department;
    }

    public Project getProject() {
        return project;
    }

    public void setProject( Project project ) {
        this.project = project;
    }

    public double calculateYearlySalary(){
        double yearlySalary;
        yearlySalary = dailyRate * WORKING_DAYS;
        return yearlySalary;
    }
    public String toString(){
        String eOutput;
        eOutput = "Employee Name: " + employeeName + " Yearly Salary: " + calculateYearlySalary();
        eOutput = eOutput + department;
        eOutput = eOutput + project;
        return eOutput;
    }
}
