//University.cpp
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;

#include "University.h"

//initialize static variables
bool University::failure = false;
bool University::success = true;
long Course::nextCRN = 200;
long Department::nextDepartID=100;
long Student::nextStId=500;
long Faculty::nextFacultyID=600; 

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
//-----------------------------------Course Public Begin--------------------------------------------
Course::Course()//constructor
{//default begin
  CRN=nextCRN++;//Course number
  maxAvailableSeats=0;//seats avaiable in course
  name=" ";//name of the class
  departID=0;//departmentID of class
  assignedSeats=0;//assigned seat
  isTaughtBy=0;//teacher of course 
}//default end
Course::Course(long crn,int max,string Name,long depID,long Assign,long teach)
{
  CRN=crn;//Course number
  maxAvailableSeats=max;//seats avaiable in course
  name=Name;//name of the class
  departID=depID;//departmentID of class
  assignedSeats=Assign;//assigned seat
  isTaughtBy=teach;//teacher of course 
}
void Course::print()const//print func course
{
  cout<<"Course Number: "<<CRN<<endl;
  cout<<"Max Seats Available: "<<maxAvailableSeats<<endl;
  cout<<"Course Name: "<<name<<endl;
  cout<<"Department ID: "<<departID<<endl;
  cout<<"Assigned Seat: "<<assignedSeats<<endl;
  cout<<"Teacher ID: "<<isTaughtBy<<endl;
}
//===================================Course Public End=============================================
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
//===================================Faculty Public End========================
//===================================CHECK FUNCTIONS BEGIN=====================
bool University::checkDeptExist(long tDepId)
{
  bool found=false;
  for (int i=0;i<Departments.size();i++)
    {
      if (tDepId==Departments[i].id)
	{
	  found= true; 
	}
      else
	{
	  ;// return false;
	}
    }
  return found;
}

bool University::checkFacultyExists(long fDepID)
{
  bool found=false;
  
  for (int i=0;i<Faculties.size();i++)//goes through the all faculty vector
    {
      if(fDepID == Faculties[i].id)//if fDepId = departId of any Faculty
	{//will return true if equal
	  found= true;
	}
      else 
	{//will return false if cannot find a match
	  ;      
	} 
    }  
 return found;
}

bool University::checkDeptName(string deptName)
{
  bool found=false;
  for (int i=0;i<Departments.size();i++)
    {
      if(deptName==Departments[i].name)//if same then true
	{
	  found=true;
	}
      else 
	;
    }
  return found;
}

bool University::checkCourseExists(long cCRn)
{
  bool found=false;
  for (int i=0;i<Courses.size();i++)
    {
      if (cCRn==Courses[i].CRN)
	{
	  found=true;
	}
      else
	;
    }
  return found;
}

bool University::checkStudentExists(long sStID)
{
  bool found=false;
  for (int i=0;i<Students.size();i++)
    {
      if (sStID==Students[i].id)
	{
	  found= true;
	}
      else
	;
    }
  return found;
} 
//-----------------------------------CHECK FUNCTIONS END-----------------------------------------------
//==============================================University Public Begin===============================
bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)
{
  bool valid=false;//create a bool named valid and initialize it to false
  if (depChairId != 0)//if the depID is not 0 then have to confirm if the id is found
    {
      valid = checkDeptExist(depChairId);//a routine that sees if the ID exists or not by comparing to the other IDS
      if (valid==false)//if it is not found then say it does not exist and return fail
	{
	  cout<<"The Department Chair ID does not Exists. Could not Create a New Department"<<endl;
	  return failure;
	}
      else
	  {//if it is found then create a new department
	    Department d1;//declares a single class variable Department
	    d1.name=depName;
	    d1.location=depLoc;
	    d1.chairID=depChairId;
	    Departments.push_back(d1);//push something into the vector
	    return success;
	  };
    }
  else//if the depID is 0 then do it
    {
      Department d1;
      d1.name=depName;
      d1.location=depLoc;
      d1.chairID=depChairId;
      Departments.push_back(d1);
    }
  return success;
}
//----------------------------------------------------------------------------

bool University::RemoveADepartment(long depId)
{
  bool valid=false;
  valid=checkDeptExist(depId);
  
  if (valid==false)
    {
      cout<<"The Department does not exist! (Remove A Department)"<<endl;
      return failure;
    }
  else
    {
      for (int i=0;i<Departments.size();i++)//will go through all of the Departments
	{
	  if (depId==Departments[i].id)
	    {
	      Departments.erase(Departments.begin()+i);
	    }
	}
      return success;
    }
  
}

//----------------------------------------------------------------------------

bool University::CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)
{
  Student s1;//declares a vector to fill
  bool valid=false;
  if (sMajor == "0")//if sMajor is 0 
    {
      cout<<"Student has not chosen a major"<<endl;
      s1.name=sName;
      s1.email=sEmail;
      s1.address=sAddress;//fill the vector
      s1.dateOfBirth=sDateOfBirth;
      s1.gender=sGender;
      s1.yearOfStudy=sYearOfStudy;
      s1.major=sMajor;
      s1.advisorID=sAdvisorId;
      Students.push_back(s1);
    }
  else  //if sMajor is not 0
    {
      valid=checkDeptName(sMajor);
      if (valid==true)
	{//if department is found begin
	  s1.name=sName;//fill the vector
	  s1.email=sEmail;
	  s1.address=sAddress;
	  s1.dateOfBirth=sDateOfBirth;
	  s1.gender=sGender;
	  s1.yearOfStudy=sYearOfStudy;
	  s1.major=sMajor;
	  s1.advisorID=sAdvisorId;  
	  Students.push_back(s1);
	  return success; 
	}
      else//if valid is false
	{
	  cout<<"This Major is an Invalid Major for the Student"<<endl;
	  return failure;
	}
      
    }
}
//----------------------------------------------------------------------------

bool University::RemoveAStudent(long sStId)//OPTIONAL
{  
    bool valid=false;
    valid=checkStudentExists(sStId);
    if(valid==false)
      {
	cout<<"The Student ID: "<<sStId<<" does not exist."<<endl;
	return failure;
      }
    else//valid==true
      {
	for(int i=0;i<Students.size();i++)//will go through the students 
	  {
	    if(Students[i].id==sStId)
	      {
		Students.erase(Students.begin()+i);
	      }
	    else
	      ;
	  }
	return success;
      }
}

//----------------------------------------------------------------------------

bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{//New Course Begin
  bool valid=false;
  bool valid2=false;
  if (cTaughtBy == 0)//if sMajor is 0
    {//if statement begin
      cout<<"There is no Teacher for "<<cName<<endl;
    }//if end
  else  //if sMajor is not 0
    {//else begin
      valid=checkFacultyExists(cTaughtBy);
      valid2=checkDeptExist(cDepId);
      
      if (valid==true && valid2==true)
        {//if department is found begin
          Course c1;
	  c1.name=cName;
	  c1.departID=cDepId;
	  c1.isTaughtBy=cTaughtBy;
	  c1.maxAvailableSeats=cMaxSeat;
          Courses.push_back(c1);
          return success;
        }//if department is found end
      else//if valid or valid2 is false
        {//if valid is false begin
          cout<<"This Teacher ID is not valid"<<endl;
          return failure;//University::failure;  
        } //if valid false ending  
    }//else statement end
}
//----------------------------------------------------------------------------

bool University::RemoveACourse(long cCRN)//OPTIONAL
{
  bool valid=false;
  valid=checkCourseExists(cCRN);
  if (valid==true)
    {
      for (int i=0;i<Courses.size();i++)//will go through all the courses
	{
	  if (Courses[i].CRN==cCRN)
	    {
	      Courses.erase(Courses.begin()+i);
	    }
	  else
	    ;
	}
      return success;
    }
  else
  return failure;
}

 //----------------------------------------------------------------------------
bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender,float fSalary, int fYearOfExp, long fDepId)
{
  bool valid=false;
  valid=checkDeptExist(fDepId);
  if (valid==false)
    {
      cout<<"This fDepID does not exist"<<endl;
      return failure;
    }
  else//valid is true 
    {
      Faculty f1;
      f1.name=fName;
      f1.email=fEmail;
      f1.address=fAddress;
      f1.dateOfBirth=fDateOfBirth;
      f1.gender=fGender;
      f1.salary=fSalary;
      f1.yearOfExp=fYearOfExp;
      f1.departID=fDepId;
      Faculties.push_back(f1);
      return success;
    }
}
//----------------------------------------------------------------------------
bool University::RemoveAFaculty(long fFactId)//OPTIONAL
{
  bool valid=false;
  valid=checkFacultyExists(fFactId);
  if(valid==false)
    {
      cout<<"The faculty ID "<<fFactId<<" does not exists"<<endl;
      return failure;
    }
  else//if valid is true
    {
      for(int i=0;i<Faculties.size();i++)
	{
	  if (Faculties[i].id==fFactId)
	    {
	      Faculties.erase(Faculties.begin()+i);
	    }
	  else
	    ;
	}
      return success;
    }
  
}
//----------------------------------------------------------------------------
 bool University::ListCoursesTaughtByFaculty(long facultyId)
{
  bool valid=false;
  int x=0;//a counter for courses 
  valid=checkFacultyExists(facultyId);
  if (valid==true)
    {
      cout<<"The Courses Taught by "<<facultyId<<" are: "<<endl;
      for (int i=0;i<Courses.size();i++)
	{
	  if (Courses[i].isTaughtBy==facultyId)
	    {
	      cout<<"Course ID: "<<Courses[i].CRN<<endl;
	      cout<<"Course Name: "<<Courses[i].name<<endl;
	      x++;
	    }
	  else
	    ;
	}
      if (x==0)
	{
	  cout<<"No classes were taught by this teacher id"<<endl;
	}    
      else
	;
    }
  else//if valid is false
    cout<<"The Faculty Id "<<facultyId<<" in ListCoursesTaughtByFaculty does not exists"<<endl;
    ;
    return valid;
}
//----------------------------------------------------------------------------

bool University::ListCoursesTakenByStudent(long studentId)
{
  bool  valid=false;
  valid=checkStudentExists(studentId);
  if (valid==true)
    {
      cout<<"The Courses that Student "<<studentId<<" are taking are: "<<endl;
      for (int i=0;i<Students.size();i++)//loop that goes through all of the students
	{
	  if (Students[i].id==studentId)//if a student's id is equal to the given
	    {
	      for ( int x=0;x < Students[i].coursesTaken.size();x++)///go through all of the student's courses
		{  
		  cout<<"Course Name:"<<Students[i].coursesTaken[x].name<<endl;
		  cout<<"Course ID: "<<Students[i].coursesTaken[x].CRN<<endl;  
		}
	    }
	  else//if not the same do nothing
	    ;
	}
      return success;
    }
  else//if valid == false
    {
      cout<<"The student id "<<studentId<<" in ListCoursesTakenByStudents is not valid"<<endl;
      return failure;
    }
}
//----------------------------------------------------------------------------

bool University::ListFacultiesInDepartment (long departId)
{
  bool valid=false;
  valid=checkDeptExist(departId);
  if (valid==true)
    {
      cout<<"The Faculty members in "<<departId<<" are: "<<endl;
      for (int i=0;i<Faculties.size();i++)
	{
	  if (Faculties[i].departID==departId)
	    {
	      cout<<"Faculty ID: "<<Faculties[i].id<<endl;
	      cout<<"Faculty Name: "<<Faculties[i].name<<endl;
	    }
	  else
	    ; 
	  //if the departmens id is not the same do nothing
	}
      return success;
    }
  else//if valid is true
    {
      cout<<"The Department ID "<<departId<< " does not exists"<<endl;
      return failure;
    }
}
//-------------------------------------------------------------------
bool University::ListStudentsOfAFaculty(long facultyId)
{
  bool found=false;
  found=checkFacultyExists(facultyId);
  if (found==true)
    {
      cout<<"The Students of Faculty ID: "<<facultyId<<endl;
      for (int i=0;i<Students.size();i++)
	{
	  if(facultyId==Students[i].advisorID)
	    {
	      cout<<"Student Id: "<<Students[i].id<<endl;
	      cout<<"Student Name: "<<Students[i].name<<endl;      
	    }
	}
    }
  else //if the faculty id was not found
    {
      cout<<"The faculty id "<<facultyId<<" used in List Students of a Faculty was not found."<<endl;
      return failure;
    } 
  // - This routine lists all the students (studentId and studentName) of a particular Faculty
}
//----------------------------------------------------------------------------
bool University::ListCoursesOfADepartment(long departId)
{
  bool found=false;
  found=checkDeptExist(departId);
  if (found==true)
    {
      cout<<"The Courses of Department "<<departId<<" are:"<< endl;
      for (int i=0;i<Courses.size();i++)
	{
	  if (Courses[i].departID==departId)
	    {
	      cout<<"Course Name: "<<Courses[i].name<<endl;
	      cout<<"Course Num: "<<Courses[i].CRN<<endl;
	    }
	}
      return success;
    }
  else //if the depart id was not found
    {
      cout<<"The Department ID "<<departId<<" in list courses of a department was not found"<<endl;
      return failure;
      /*
	- This routine lists all the courses offered by a particular department
      */
    }
}
//----------------------------------------------------------------------------
bool University::AddACourseForAStudent(long courseId, long stId)
{
  bool valid=false;
  bool valid2=false;
  valid=checkCourseExists(courseId);
  valid2=checkStudentExists(stId);
  if (valid==true && valid2==true)
    {
      for (int i=0;i < Students.size();i++)//will go through all the students to find it
	{
	  if (Students[i].id==stId)//if the student's id is the same
	    {//it will now go through the courses for this student
	      for (int y=0; y < Courses.size();y++)//will go through the courses
		{
		  if (Courses[y].CRN==courseId)//checks the courses ids
		    { 
		      Courses[y].assignedSeats++;
		      if (Courses[y].assignedSeats <= Courses[y].maxAvailableSeats) 
			{//if the assigned seats is less than or equal to max
			  Students[i].coursesTaken.push_back(Courses[y]);//puts the course that matches and places into vector
			}//then you can add the class
		      else
			{//if it is greater than max then you cannot add
			  cout<<"Sorry this Class is Full"<<endl;
			}
		    }
		  else
		    ;
		}
	    }
	  else
	    ;
	} 
      //cout<<"This means AddACourseForAstudent works"<<endl;
      return success;
    }
  else
    {
      cout<<"The validity test for Course ID: "<<courseId<<" and Student ID: "<<stId<<" in addACourseForAStudent did not pass"<<endl;
      return failure;
    }
  /*
    - This routine adds a course for a student
  */
}
//----------------------------------------------------------------------------

bool University::DropACourseForAStudent(long courseId, long stId)//optional
{
  bool valid=false;
  bool valid2=false;
  valid=checkCourseExists(courseId);
  valid2=checkStudentExists(stId);
  if (valid ==true && valid2==true)
    {
      for(int i=0;i<Students.size();i++)
	{
	  if (Students[i].coursesTaken[i].CRN==courseId)
	    {
	      for (int y=0;y<Courses.size();y++)//goes through all the courses
		{//for loop that decrements the assigned seat
		  if(Students[i].coursesTaken[i].CRN==Courses[y].CRN); 
		  {
		    Courses[y].assignedSeats--;
		  }
		}	      
	      for (int x=0;x<Students[i].coursesTaken.size();x++)
		{//for loop that erases from vector
		  Students[i].coursesTaken.erase(Students[i].coursesTaken.begin()+x);
		}
	      return success;
	    }
	  else;
	}
    }
  else//if valid is false
    {
      cout<<"Either course Id or stId does not exists"<<endl;
      return failure;
    }
}

//----------------------------------------------------------------------------
bool University::AssignDepartmentChair(long facultyId, long departId)
{ 
  bool valid=checkFacultyExists(facultyId);
  bool valid2=checkDeptExist(departId);
  if (valid==true && valid2==true)
    {
      for (int i=0;i<Departments.size();i++)//checks through all the departments
	{
	  if (departId==Departments[i].id)//if the id is the same 
	    { 
	      Departments[i].chairID=facultyId;
	      cout<<"The Department Chair of "<<departId<<" is "<<facultyId<<endl;
	    }
	  else//do nothing if not the same 
	    ;
	}
      return success;	  
    }
  else 
    {
      if (valid==true)
	{
	  cout<<"The Faculty ID: "<<facultyId<<" is valid "<<endl;
	}      
      else 
	{
	  cout<<"The Faculty ID: "<<facultyId<<" is invalid"<<endl;
	}
      if (valid2==true)
	{
	  cout<<"The Department ID: "<<departId<<" is valid "<<endl;
	}
      else
	{
	  cout<<"The Department ID: "<<departId<<" is invalid"<<endl;
	}  
      return failure;
    }
  /*
    - This routine assigns a chair to a department
  */
}
int University::findDepartment(int dID)//function that finds the Department
{
  for (int i=0;i<Departments.size();i++)
    {
      if (Departments[i].id == dID)
	{
	  return i;
	}
    }
}
//----------------------------------------------------------------------------
bool University::AssignInstructorToCourse (long facultyId, long courseId)
{
  bool valid=checkFacultyExists(facultyId);//validates faculty id
  bool valid2=checkCourseExists(courseId);//validates course id
  int i=findCourse(courseId);
  if (valid ==true && valid2==true)
    {
      Courses[i].isTaughtBy=facultyId;
      return true;     
    }
  else 
    {
      cout<<"The faculty id is : "<<valid<<endl;
      cout<<"The course id is: "<<valid2<<endl;
      return false;
    }
  /*
    - This routine assigns a course to an instructor to teach
  */
}
int University::findCourse(long cID)
{
  for (int i =0; i<Courses.size();i++)
    {
      if (Courses[i].CRN==cID)
	{
	  return i;
	}
    }
}
//----------------------------------------------------------------------------
bool University::ListDepartments()
{
  for (int i=0;i<Departments.size();i++)
    {
      cout<<"Department ID: "<<Departments[i].id<<endl;
      cout<<"Department Name: "<<Departments[i].name<<endl;
    }
  cout<<endl;
  /*
    - This method should list the department id's and department names only
  */
}
//----------------------------------------------------------------------------
bool University::ListStudents()
{
  for (int i=0; i<Students.size();i++)
    {
      cout<<"Student ID: "<<Students[i].id<<endl;
      cout<<"Student Name: "<<Students[i].name<<endl;     
    }
  cout<<endl;
  /*
    - This method should list the student id's and student names only
  */
}
//----------------------------------------------------------------------------
bool University::ListCourses()
{
  for (int i=0;i<Courses.size();i++)
    {
      cout<<"Course ID: "<<Courses[i].CRN<<endl;
      cout<<"Course Name: "<<Courses[i].name<<endl;
    }
  cout<<endl;
  /*
    - This method should list the course id's and course names only
  */
}
//----------------------------------------------------------------------------
bool University::ListFaculties()
{
  for (int i=0;i <Faculties.size();i++)
    {
      cout<<"Faculty ID: "<<Faculties[i].id<<endl;
      cout<<"Faculty Name: "<<Faculties[i].name<<endl;     
    }
  cout<<endl;
  /*
    - This method should list the faculty id's and faculty names only
  */
}
//----------------------------------------------------------------------------
  /*
    - open the transaction file and process it one by one
  */
bool University::ProcessTransactionFile(string fileName)
{
  string command;//variable that will get the command
  ifstream fin;
  string name, email, dob, address, gender;
  string major, location;
  long chair, id, fId, cId,sId,dId;
  long advisorID, teacher;
  int exp;
  int yearOfStudy;
  int seats;
  float salary;
  fin.open("TransactionFile.txt");//opens transaction file 
  if(!fin)
    {
      cout <<fileName <<" does not exist and could not be opened!" << endl << endl;
    }
  else
    {
      while (fin>>command)//while there are commands
	{//while loop beginning
	  if(command == "CreateNewDepartment")//if the command is CreateNewDepartment
	    { 
	      fin>>name;
	      fin>>location;
	      fin>>chair; 
	      CreateNewDepartment(name,location,chair);
	    }
	  else if(command=="RemoveADepartment")//if command is RemoveADepartment
	    {
	      fin>>dId;
	      RemoveADepartment(dId);
	      //cout<<"The command for Remoeve A Department Works"<<endl;
	    }
	  else if(command=="CreateNewStudent")
	    {
	      fin>>name;
	      fin>>email;
	      fin>>address;
	      fin>>dob;
	      fin>>gender;
	      fin>>yearOfStudy;
	      fin>>major;
	      fin>>advisorID;
	      CreateNewStudent(name,email,address,dob,gender,yearOfStudy,major,advisorID);
	    } 
	  else if(command=="RemoveAStudent")
	    {
	      fin>>sId;
	      RemoveAStudent(sId);
	      //cout<<"The command fore remove a student works"<<endl;
	    }
	  else if(command=="CreateNewCourse")
	    {
	      fin>>name;
	      fin>>id;
	      fin>>teacher;
	      fin>>seats;
	      CreateNewCourse(name,id,teacher,seats);
	    }
	  else if(command=="RemoveACourse")
	    {
	      cout<<"The command for remove a course works"<<endl;
	    }
	  else if(command=="CreateNewFaculty")
	    {
	      fin>>name;
	      fin>>email;
	      fin>>address;
	      fin>>dob;
	      fin>>gender;
	      fin>>salary;
	      fin>>exp;
	      fin>>id;
	      CreateNewFaculty(name,email,address,dob,gender,salary,exp,id);
	    }
	  else if(command=="RemoveAFaculty")//optional
	    {
	      fin>>fId;
	      RemoveAFaculty(fId);
	      //cout<<"The command for remove a faculty works"<<endl;
	    }
	  else if(command=="ListCoursesTaughtByFaculty")
	    {
	      fin>>fId;
	      ListCoursesTaughtByFaculty(fId);
	      //cout<<"List Courses Taught by Faculty Works"<<endl;
	      cout<<endl;
	    }
	  else if(command=="ListCoursesTakenByStudent")
	    {
	      fin>>sId;
	      ListCoursesTakenByStudent(sId);
	      //cout<<"List course taken by student works" <<endl;
	      cout<<endl;
	    }
	  else if(command=="ListFacultiesInDepartment")
	    {
	      fin>>dId;
	      ListFacultiesInDepartment(dId);
	      //cout<<"List Faculties in department works"<<endl;
	      cout<<endl;
	    }
	  else if(command=="ListStudentsOfAFaculty")
	    {
	      fin>>fId;
	      ListStudentsOfAFaculty(fId);
	      //cout<<"list students of a faculty works" <<endl;
	      cout<<endl;
	    }
	  else if(command=="ListCoursesOfADepartment")
	    {
	      fin>>dId;
	      ListCoursesOfADepartment(dId);
	      //cout<<"list courses of a department works"<<endl;
	      cout<<endl;
	    }
	  else if(command=="AddACourseForAStudent")
	    {
	      fin>>cId;
	      fin>>sId;
	      //cout<<"Add a coruses for a student"<<endl;
	      AddACourseForAStudent(cId,sId);
	      
	    }
	  else if(command=="DropACourseForAStudent")//optional
	    {
	      fin>>cId;
	      fin>>sId;
	      DropACourseForAStudent(cId,sId);
	      //cout<<"Drop a course for a student works"<<endl;
	    }
	  else if(command=="AssignDepartmentChair")
	    {
	      //cout<<"Assign department chair works"<<endl;
	      fin>>fId;
	      fin>>cId;
	      AssignDepartmentChair(fId,cId);
	      cout<<endl;
	    }
	  else if(command=="AssignInstructorToCourse")
	    {
	      fin>>fId;
	      fin>>cId;
	      //cout<<"Assign Instructor to coursee works"<<endl;
	      AssignInstructorToCourse(fId,cId);
	      
	    }
	  else if(command=="ListDepartments")
	    {
	      ListDepartments();
	      cout<<endl;
	    }
	  else if(command=="ListStudents")
	    {
	      ListStudents();
	      cout<<endl;
	    }
	  else if(command=="ListCourses")
	    {
	      ListCourses();
	      cout<<endl;
	    }
	  else if(command=="ListFaculties")
	    {
	      ListFaculties();
	      cout<<endl;
	    }
	  else
	    ;
	  
	}//while loop end
      fin.close();
    }//else loop end
  
  return success;
}//function end

