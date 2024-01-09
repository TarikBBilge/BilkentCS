/**
 * @(#)Project.java
 *
 *
 * @author Lori
 * @version 1.00 2020/3/29
 */
import java.util.Calendar;

public class Project 
{
   // constants 
   private static final double TAX = 0.17;
   private static final int OVERHEAD = 50000;
   private static final int EMP_HOURS_WEEK = 40;
   
   // static data members
   private static int projectCounter = 1000;
   
   // properties
   private String projectId;
   private String projectName;
   private char projectType;
   private int personHours;
   private double ratePerHour;
   private int projectWeeks;
   
   // constructors
   public Project( String projectName, int personHours, double ratePerHour, 
                  int projectWeeks )
   {
      this.projectName = projectName;
      setPersonHours( personHours );
      setRatePerHour( ratePerHour );
      setProjectType();
      setProjectWeeks( projectWeeks );
      setProjectId();
      projectCounter++;
   }
   
   // methods
   private void setProjectId()
   {
      projectId = Calendar.getInstance().get(Calendar.YEAR) + "-" + projectCounter;
   }
   
   public String getProjectId(){
      return projectId;
   }
   
   public void setProjectName( String projectName )
   {
      this.projectName = projectName;
   }
   
   public String getProjectName()
   {
      return projectName;
   }
   
   public void setProjectType()
   {
      double projectCost = calculateProjectCost();
      if ( projectCost > 200000 )
      {
         //major
         projectType = 'm';
      }
      else if( projectCost > 100000 )
      {
         //advanced
         projectType = 'a';
      }
      else if (projectCost > 0 )
      {
         //standard
         projectType = 's';
      }
      else {
         //inactive
         projectType = 'i';
      }
   }
   
   public char getProjectType()
   {
      return projectType;
   }
   
   public void deactivateProject()
   {
      projectType = 'i';
   }
   
   public void setPersonHours( int personHours )
   {
      if( personHours  > 0 )
         this.personHours = personHours;
      else 
         this.personHours = 0;
   }
   
   public int getPersonHours(){
      return personHours;
   }
   
   public void setRatePerHour( double ratePerHour ){
      if ( ratePerHour > 0.0 )
         this.ratePerHour = ratePerHour;
      else 
         this.ratePerHour = 0.0;
   }
   
   public double getRatePerHour()
   {
      return ratePerHour;
   }
   
   public void setProjectWeeks( int projectWeeks )
   {
      if( projectWeeks  > 0 )
         this.projectWeeks = projectWeeks;
      else 
         this.projectWeeks = 0;
   }
   
   public int getProjectWeeks()
   {
      return projectWeeks;
   }
   
   public double calculateProjectCost()
   {
      double cost;
      cost = personHours * ratePerHour;
      if( cost > 20000 )
         cost = cost + OVERHEAD;
      cost = cost + cost * TAX;
      return cost;
   }
   
   public int calculatePersonResources()
   {
      double hoursPerWeek;
      double resources;
      hoursPerWeek = (double)personHours / projectWeeks;
      resources = hoursPerWeek / EMP_HOURS_WEEK;
      return (int)Math.ceil(resources);
   }
   
   public int compareProjects( Project proj )
   {
      if ( this.calculateProjectCost() > proj.calculateProjectCost() )
      {
         return 1;
      }
      else if ( this.calculateProjectCost() > proj.calculateProjectCost() )
      {
         return -1;
      }
      else {
         return 0;
      }
   }
   
   public String toString()
   {
      String output;
      
      output = "";            
      if ( getProjectType() == 'i' )
      {
         output = output + "\n-------INACTIVE PROJECT------\n";
         output = output + "Project Name: " + projectName + "\n";
         output = output + "Project ID: " + projectId + "\n";
      }
      else {
         output =  "\nProject Name: " + projectName + "\n";
         output = output + "Project ID: " + projectId + "\n";
         output = output +"Project Type: " + projectType + "\n";
         output = output + "Team Size: " + calculatePersonResources() + "\n";
         output = output + "Estimated Project Cost: " + calculateProjectCost() + "\n";
      }
      
      return output; 
   }
   
   public boolean equals( Project other )
   {
      System.out.println( "in Project equals..." );
      return projectId.equals( other.projectId ) && 
         projectName.equals( other.projectName ) && 
         projectType == other.projectType &&
         personHours == other.personHours &&
         ratePerHour == other.ratePerHour &&
         projectWeeks == other.projectWeeks;
   }
   
}
