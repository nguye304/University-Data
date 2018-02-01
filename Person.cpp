#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
#include "Person.h"
//-----------------------------------Person Public Begin------------------------------------------


Person::Person()
{//default constructor
  id=0;
  name=" ";
  email=" ";
  address=" ";
  dateOfBirth=" ";
  gender=" ";
}//default constructor end

Person::Person(long ID,string Name,string Email,string Address,string DOB,string Gender)
{//constructor begin
  id=ID;
  name=Name;
  email=Email;
  address=Address;
  dateOfBirth=DOB;
  gender=Gender;
}//constructor end
void Person::print()const
{
  cout<<"ID: "<<id<<endl;
  cout<<"Name: "<<name<<endl;
  cout<<"Address: "<<address<<endl;
  cout<<"Date Of Birth: "<<dateOfBirth<<endl;
  cout<<"Gender: "<<gender<<endl;
}

//===================================Person Public End=============================================
