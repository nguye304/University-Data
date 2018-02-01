#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include "Faculty.h"
#include "Person.h"

//-----------------------------------Faculty Public Begin-----------------------------------------

Faculty::Faculty()//default constructor
{
  id=nextFacultyID++;
  salary=0;
  yearOfExp=0;
  departID=0;
}
Faculty::Faculty(float Salary,int exp,long depID)
{
  salary=Salary;
  yearOfExp=exp;
  departID=depID;
}
void Faculty::print()const//print func faculty
{
  cout<<"Salary: "<<salary<<endl;
  cout<<"Years of Experience: "<<yearOfExp;
  cout<<"Department ID: "<<departID;


}

//===================================Faculty Public End============================================
