#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include "Course.h"

//-----------------------------------Course Public Begin--------------------------------------------
Course::Course()//constructor
{//default begin
  CRN=nextCRN++;//Course number
  maxAvailableSeats=0;//seats avaiable in course
  name=" ";//name of the class
  departID=0;//departmentID of class
  assignedSeats=0;//assigned seat
  isTaughtBy=0;//teacher of course

}//default end

Course::Course(long crn,int max,string Name,long depID,long Assign,long teach)
{
  CRN=crn;//Course number
  maxAvailableSeats=max;//seats avaiable in course
  name=Name;//name of the class
  departID=depID;//departmentID of class
  assignedSeats=Assign;//assigned seat
  isTaughtBy=teach;//teacher of course

}
void Course::print()const//print func course
{
  cout<<"Course Number: "<<CRN<<endl;
  cout<<"Max Seats Available: "<<maxAvailableSeats<<endl;
  cout<<"Course Name: "<<name<<endl;
  cout<<"Department ID: "<<departID<<endl;
  cout<<"Assigned Seat: "<<assignedSeats<<endl;
  cout<<"Teacher ID: "<<isTaughtBy<<endl;

}
//===================================Course Public End=============================================
