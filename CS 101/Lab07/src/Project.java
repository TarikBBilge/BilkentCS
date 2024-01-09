/*
 * This program provides methods to Project Application.
 * Lab 07 Assignment
 * Author: Tarik Berkan Bilge
 * Date: 08.04.2021
 */
public class Project
{
    //data members
    private final double    TAX = 0.13;
    private final int       OVERHEAD = 50000,
                            EMP_HOURS_WEEK = 45;
    private static int  projectCounter = 5000;
    private String  projectId = "",
                    projectName,
                    projectType = "";
    private double  personHours,
                    ratePerHour,
                    projectWeeks;

    public Project( String projectName , double personHours , double ratePerHour , double projectWeeks ){
        projectCounter++;
        this.projectName = projectName;
        this.personHours = personHours;
        this.ratePerHour = ratePerHour;
        setProjectId( projectCounter );
        setProjectType();
        this.projectWeeks = projectWeeks;
    }
    //getters
    public String getProjectName(){
        return projectName;
    }
    public String getProjectId(){
        return projectId;
    }
    public String getProjectType(){
        return projectType;
    }
    public double getPersonHours(){
        return personHours;
    }
    public double getRatePerHour(){
        return ratePerHour;
    }
    public double getProjectWeeks(){
        return projectWeeks;
    }
    //setters
    public void setProjectName( String name ){
        this.projectName = name;
    }
    public void setPersonHours( double personHours ){
        if( personHours > 0 ){
            this.personHours = personHours;
        }
        this.personHours = 0;
    }
    public void setRatePerHour( double ratePerHour ){
        if( ratePerHour > 0 ){
            this.ratePerHour = ratePerHour;
        }
        this.ratePerHour = 0;
    }
    public void setProjectWeeks( double projectWeeks ){
        if( projectWeeks > 0 ){
            this.projectWeeks = projectWeeks;
        }
        this.projectWeeks = 0;
    }
    private void setProjectId( int projectCounter ){
        this.projectId = "2021-" +  projectCounter;
    }
    public void setProjectType(){
        double projectCost = calculateProjectCost();
        //if project has major cost it is (m)ajor project
        if( projectCost > 1000000 ){
            this.projectType = "m";
        }
        //if project has large cost it is (l)arge-scale project
        else if( projectCost > 500000 ){
            this.projectType = "l";
        }
        //if project has standard cost it is (s)tandard project
        else if( projectCost > 0 ){
            this.projectType = "s";
        }
        //if project has not a cost it is (i)nactive project
        else if( projectCost == 0 ){
            this.projectType = "i";
        }
    }

    public void deactivateProject(){
        personHours = 0;
        ratePerHour = 0;
        projectType = "i";
        projectCounter = 50001;
    }
    public void activateProject( double personHours , double ratePerHour ){
        setPersonHours(personHours);
        setRatePerHour(ratePerHour );
        setProjectType() ;
    }
    public double calculateProjectCost(){
        double projectCost;
        if( personHours * ratePerHour < 20000 ){
            projectCost = personHours * ratePerHour * ( 1 + TAX );
        }
        projectCost = ( ( personHours * ratePerHour ) + OVERHEAD ) * ( 1 + TAX );
        return projectCost;
    }
    public int calculatePersonResources(){
        int personResources = (int) ( personHours / ( projectWeeks * EMP_HOURS_WEEK ) );
        return personResources;
    }
    public int compareProjects( Project p1 ){
        if( calculateProjectCost() > p1.calculateProjectCost() ){
            return 1;
        }
        else if( calculateProjectCost() < p1.calculateProjectCost() ){
            return -1;
        }
        return 0;
    }
    public String toString() {
        String output = "";
        //if it is an active project show this output
        if( getProjectType() != "i" ) {
            output = output + "Project Name: " + projectName + "\n";
            output = output + "Project ID: " + projectId + "\n";
            output = output + "Project Type: " + projectType + "\n";
            output = output + "Team Size: " + calculatePersonResources() + "\n";
            output = output + "Estimated Project Cost: " + (double)Math.round( calculateProjectCost() ) + "\n";
        }
        //if it is an inactive project show this output
        else {
            output = output + "-------INACTIVE PROJECT------" + "\n";
            output = output + "Project Name: " + projectName + "\n";
            output = output + "Project ID: " + projectId + "\n";
        }
        return output;
    }
}
