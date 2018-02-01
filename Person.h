#ifndef Person_h
#define Person_h
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;
//=======================================
//==================Person Class Begin======================DONE
class Person//Parent class that gets the basic info for Faculty and Student
{friend class University;

 protected:
  long id;
  string name;
  string email;
  string address;
  string dateOfBirth;//birthday
  string gender;

 public:
  Person();
  //  ~Person();
  Person(long ID,string Name,string Email,string Address,string DOB,string Gender);
  void print()const;
};

//==================Person Class End========================DONE


#endif
