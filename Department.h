#ifndef Department_h
#define Department_h
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
#include "University.h"

//=================Department class Begin===================DONE
class Department
{
  friend class University;
  friend bool checkDeptName(string deptName);
  friend bool checkDeptExist(long tDepId);
 protected:
  long id;//id of department
  string name;//name of department
  string location;//location of department
  long chairID;//ID number of department chair
  static long nextDepartID;//initialize to 0
 public://doo all of the below for all classes
  Department();//constructor
  //~Department();//deconstructor
  Department(string depName,string depLoc,long chairID );//default constructor
  void print()const;//print function
};
//=================Department Class End=======================DONE



#endif

