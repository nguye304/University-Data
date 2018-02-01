#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
#include "Department.h"

//------------------------------Department Public Begin-------------------------------------
Department::Department()//default constructor for Department
{//default constructor begin
  id=nextDepartID++;//ID will add by 1 every time it is used
  name=" ";//initialize name to space
  location=" ";//initialize location to space
  chairID=0;//initialize location to 0

}//default end
Department::Department(string depName, string depLoc,long depChairID)//construtor for Department
{//Constructor begin
  name=depName;
  location=depLoc;
  chairID=depChairID;
}//constructor end
void Department::print()const
{//print begin department
  cout<<"Department ID is: "<<id<<endl;
  cout<<"Department Name is: "<<name<<endl;
  cout<<"Department Location is: "<<location<<endl;
  cout<<"Department Chair ID is: "<<chairID<<endl;

}//print end department

//===================================Department Public End========================================
