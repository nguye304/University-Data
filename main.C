/*
PROGRAMMED BY KEVIN NGUYEN 
CLASS: CS211
DATE: November 15th 2016
PROGRAM DESCRIPTION: 
This program is suppose to be a small University Database that has the 
following components:Department,Student,Faculty,Course and Fills up the DataBase through a Transaction File
EXTRA CREDIT: 
Attempted to do all of them: RemoveADepartment, RemoveAStudent,
RemoveACourse,RemoveAFaculty,DropACourseForAStudent 
=========================Main.C===================================
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

#include "University2.h"
#include "University2.cpp"

int main() 
{

  University csusm;
  string file = "TransactionFile.txt";
  csusm.ProcessTransactionFile(file);
  return 0;
}
