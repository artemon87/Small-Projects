// ----------------------------------------------------------------------
// Nothing was changed in this section

#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int const MAXSIZE = 100;
int const MAXLENGTH = 31;
int const MAXGRADE = 100;
int const LOWGRADE = 0;
int const GROUP = 10;
int const HISTOGRAMSIZE = (MAXGRADE-LOWGRADE)/GROUP + 1;

struct StudentType  
{
  int grade;
  char last[MAXLENGTH];
  char first[MAXLENGTH];
};
//-----------------------------------------------------------------------
// Prototypes
bool sortInput(istream &, StudentType [], int &);
void displayList(const StudentType [], int);
void setHistogram(int (&histogram)[HISTOGRAMSIZE][3], StudentType [], int);    
void displayHistogram(int (&histogram)[HISTOGRAMSIZE][3]);
int findAverage(StudentType [], int);

//-----------------------------------------------------------------------
int main()  {
    
  StudentType students[MAXSIZE];
  int size = 0;
  int histogram[HISTOGRAMSIZE][3];  // 2D array to store histogram
  int average = 0;
    
  ifstream infile("data1.txt");
  if (!infile)  
  {
    cout << "File could not be opened." << endl;
    return 1;
  }
    
  bool successfulRead = sortInput(infile, students, size);
  if (successfulRead)  
  {
    cout<<"List of names sorted:"<<endl;
    displayList(students, size);
    cout << endl;
    setHistogram(histogram, students, size);
    cout << "Histogram of grades: " << endl;
    displayHistogram(histogram);
    average = findAverage(students, size);
    cout << endl << "Average grade: " << average << endl << endl;
  }
  infile.close(); //closes file after its done with avarage function
  return 0;
}
//--------------------------------------------------------------------
//SortImput function per your request reads data
//And at the same time it sorts it in alfa. order

bool sortInput(istream &infile, StudentType students [], int &size)
{
   //temp location for a NS(New Student)
  StudentType tempStruct; 
 
  int i=0;
  char temp[MAXLENGTH];
  infile >> temp;
    
  while(size<MAXSIZE &&!infile.eof())
  {
    strcpy(students[size].last, temp);       
    infile >> students[size].first >> students[size].grade;
   //copying an array to temp location>>>>
    strcpy(tempStruct.last, students[size].last);  
    strcpy(tempStruct.first, students[size].first);
    tempStruct.grade=students[size].grade;         
    size++;
    infile >> temp;
        
    for(i=size-1; i>0; i--)
    {
   //checking if the grade is 0<grade>100
      if(students[size-1].grade>100 || students[size-1].grade<0) 
      {                      
        size--;
        break;
      }
   //checking if last name of NS is < than LS(last student).
   //It gets there only if "size => 2" to make sure that I have
   //something to compare with. 
      else if(strcmp(tempStruct.last, students[i-1].last)<0 && size>1) 
      {
        strcpy(students[i].last, students[i-1].last);  
        strcpy(students[i].first, students[i-1].first);
        students[i].grade=students[i-1].grade;
      }
   //checking if the first name of NS is < LS 
      else if(strcmp(tempStruct.last, students[i-1].last) == 0 &&
              strcmp(tempStruct.first, students[i-1].first)<0 && size>1)       
      {
        strcpy(students[i].last, students[i-1].last);
        strcpy(students[i].first, students[i-1].first);
        students[i].grade=students[i-1].grade;
      }
      else
      {
        break;                         
      }
    }
   //putting a new student in its correct sorted position
    strcpy(students[i].last, tempStruct.last);  
    strcpy(students[i].first, tempStruct.first);
    students[i].grade=tempStruct.grade;
    //infile >> temp;
  }
    return true;
}
//------------------------------------------------------------------------
//displayList prints out sorted list of students and their grades
void displayList(const StudentType students [], int size)
{
  for(int i=0; i<size; i++)
  {
    cout<<setw(4)<<students[i].grade<<"  "
    <<students[i].last<<"  "<<students[i].first<<endl;
  }
}

//------------------------------------------------------------------------
//this function creates the a histogram in a desired order (0-9, 10-19)
//and puts it inside the 2D array (histogram)
void setHistogram(int (&histogram)[HISTOGRAMSIZE][3],
                  StudentType students [], int size)
{
  memset(histogram, 0, sizeof(int [HISTOGRAMSIZE][3])); //resets an array
  int temp1=0;        //left side of a histogram 
  int temp2=9;        //right side of a histogram
  int startFrame=0;   //left side of a grade window (to use for stars "*")
  int endFrame=10;    //right side of agrade window (to use for stars "*")
    
  for(int i=0; i<HISTOGRAMSIZE; i++)
  {
    histogram[i][0]=temp1; //initializes our histogram 
    histogram[i][1]=temp2; //and puts the first (0-->9) to it.
    temp1+=10;          //increases lest side by 10 (10-->9)
    temp2+=10;          //increases right side by 10 (10-->19)
        
    if(temp2>MAXGRADE)
    {                   //to make sure that there is
       temp2=MAXGRADE;  //no grade higher then 100
    }
  }
  for(int a=0; a<HISTOGRAMSIZE; a++)
  {
    for(int b=0; b<size; b++) //
    {   
      //this if statement checks if there is a student
      //that has a grade between our startFrame and the endFrame  
      if(students[b].grade<endFrame && students[b].grade>=startFrame)
      {
        histogram[a][2]+=1;//adds 1 to the 3rd column in our array
                           //that will later be used to print a "*".
      }
    }
      startFrame+=10; 
      endFrame+=10;
  }
}
//------------------------------------------------------------------------
//displayHistogram uses created 2D "histogram" array and
//prints out whatever was stored 
//in it from the previous setHistogram function.
void displayHistogram(int (&histogram) [HISTOGRAMSIZE][3])
{
  for(int i=0; i<HISTOGRAMSIZE; i++)
  {
    cout<<setw(4)<<histogram[i][0]<<"-->"<<setw(4)<<histogram[i][1]<<": ";
    //checks if our histogram has a 3rd column and corresponding number
    //will print the exact amount of "*" in the next "for" loop
    if(histogram[i][2]!=0)
    {
      for(int star=0; star<histogram[i][2]; star++)
      {
        cout<<"*"; //prints a "*"
      }
    }
      cout<<endl;
  }
}
//-----------------------------------------------------------------------
//findArray adds all the grades and divides to the number of students
int findAverage(StudentType students [], int size)
{
  int total[size];
  int sum=0;
  for(int i=0; i<size; ++i)
  {
    total[i]=students[i].grade;
    sum+=total[i];
  }
  return sum/size;
}
//-------------------------------------------------------------------------