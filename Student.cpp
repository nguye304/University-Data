#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
#include "Person.h"
#include "Student.h"
//-----------------------------------Student Public Begin------------------------------------------
Student::Student()//default constructor
{
  id=nextStId++;
  yearOfStudy=0;
  major=" ";
  advisorID=0;

}
Student::Student(int years,string Major,long advID)
{
  yearOfStudy=years;
  major=Major;
  advisorID=advID;

}

void Student::print()const
{
  cout<<"Years of Study: "<<yearOfStudy<<endl;
  cout<<"Major: "<<major<<endl;
  cout<<"Advisor ID: "<<advisorID<<endl;

}
//===================================Student Public End============================================
