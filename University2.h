//University.h
#ifndef University_h
#define University_h

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

//=================Faculty Class Begin========================
class Faculty:public Person//will be a child class of Person
{friend class University;

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

//==================University Class Begin=====================
class University
{
  friend  bool checkDeptExist(long tDepId);
  friend bool checkFacultyExists(long fDepID);
  friend  bool checkDeptName(string deptName);
  friend bool checkStudentExists(long sStID);
  friend bool checkCourseExists(long cCRn);
  friend  bool isMyTeacher(Student st,long fID);
  
 protected:
  vector <Department>Departments;
  vector <Student>Students;
  vector <Course>Courses;
  vector <Faculty>Faculties;
  static bool failure;
  static bool success;
  
 public:
  //  University();
  //~University();  
  bool CreateNewDepartment(string depName, string depLoc, long depChairId);
  bool RemoveADepartment(long depId);//optional
  bool CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender,int sYearOfStudy, string sMajor, long sAdvisorId);
  bool RemoveAStudent(long sStId); //optional
  bool CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  bool RemoveACourse(long cCRN); // Optional 
  bool CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender,float fSalary, int fYearOfExp, long fDepId);
  bool RemoveAFaculty(long fFactId);//optional
  bool ListCoursesTaughtByFaculty(long facultyId);
  bool ListCoursesTakenByStudent(long studentId);
  bool ListFacultiesInDepartment (long departId);
  bool ListStudentsOfAFaculty(long facultyId);
  bool ListCoursesOfADepartment(long departId);
  bool AddACourseForAStudent(long courseId, long stId);
  bool DropACourseForAStudent(long courseId, long stId);
  bool AssignDepartmentChair(long facultyId, long departId);
  bool AssignInstructorToCourse (long facultyId, long courseId);
  
  bool ListDepartments();
  bool ListStudents();
  bool ListCourses();
  bool ListFaculties();

 
  bool checkDeptExist(long tDepId);
  bool checkFacultyExists(long fDepID);
  bool checkDeptName(string deptName);
  bool checkStudentExists(long sStID);
  bool checkCourseExists(long cCRn);
  bool isMyTeacher(Student st,long fID);
  int findDepartment(int dID);
  int findFaculty(int fID);
  int findStudent(int sID);
  int findCourse(long cID);  
 

  bool ProcessTransactionFile(string );
};
//====================University Class End==========================




#endif
