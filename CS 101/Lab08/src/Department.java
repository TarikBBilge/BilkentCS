/*
 * This program provides methods of department.
 * Lab 08 Department
 * Author: Tarik Berkan Bilge
 * Date: 15.04.2021
 */
public class Department
{
    //instance data members
    private String  deptName,
                    deptCode;

    //constructors
    public Department( String deptName, String deptCode ){
        this.deptName = deptName;
        this.deptCode = deptCode;
    }

    //methods
    public String getDeptName(){
        return deptName;
    }

    public void setDeptName(){
        this.deptName = deptName;
    }

    public String getDeptCode(){
        return deptCode;
    }

    public void setDeptCode(){
        this.deptCode = deptCode;
    }

    public boolean equals( Department other ){
        return  deptName.equals( other.deptName ) &&
                deptCode.equals( other.deptCode );
    }

    public String toString(){
        String dOutput;
        dOutput = "\nDeptName: " + deptName + " Dept Code: " + deptCode;
        return dOutput;
    }
}
