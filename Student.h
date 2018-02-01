#ifndef Student_h
#define Student_h
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
#include "Course.h"

//=====================STUDENT CLASS Begin===================
class Student:public Person//will be a child class of Person
{
  friend class University;

  friend bool checkStudentExists(long sStID);
 protected:
  int yearOfStudy;//years of study of student
  string major;//students major
  long advisorID;//student's advisor
  vector<Course>coursesTaken;//vector holding student's taken courses
  static long nextStId;//initialize to 500
 public:
  Student();
  //~Student();
  Student(int years,string Major,long advID);
  void print()const;
};
//======================Student Class End=========================



#endif
