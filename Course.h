#ifndef Course_h
#define Course_h
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
#include "University.h"
//==================Course Class Begin=======================DONE
class Course
{
  friend bool checkCourseExists(long cCRn);
  friend class University;


 protected:
  long CRN;//Course number
  int maxAvailableSeats;//seats avaiable in course
  string name;//name of the class
  long departID;//departmentID of class
  long assignedSeats;//assigned seat
  long isTaughtBy;//teacher of course
  static long nextCRN; //next course number initializeto 200
 public:
  Course();//constructor
  // ~Course();//deconstructor
  Course(long crn,int max,string Name,long depID,long Assign,long teach);
  void print()const;//print func course
};
//=================Course Class End===========================DONE


#endif
