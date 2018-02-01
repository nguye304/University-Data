#ifndef Faculty_h
#define Faculty_h
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
#include "Person.h"
#include "Student.h"
#include "Course.h"
//=================Faculty Class Begin========================
class Faculty:public Person//will be a child class of Person
{
  friend class University;

  friend bool checkFacultyExists(long fDepID);
  friend bool isMyTeacher(Student st,long fID);

 protected:
  float salary;//salary
  int yearOfExp;//years of expereince
  long departID;//dep id of faculty
  static long nextFacultyID;//initialize to 600
 public:
  Faculty();//constructor
  //~Faculty();//deconstructor
  Faculty(float Salary,int exp,long depID);
  void print()const;//print func faculty
};
//==================Faculty Class End==========================



#endif
