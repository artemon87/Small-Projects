// ----------------------------------------------------------------------------
// You write meaningful overview comments and assumptions here

#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int const MAXSIZE = 100;            // maximum number of records in total
int const MAXLENGTH = 31;           // maximum string length
int const MAXGRADE = 100;           // highest possible grade
int const LOWGRADE = 0;             // lowest possible grade
int const GROUP = 10;               // group amount
int const HISTOGRAMSIZE = (MAXGRADE-LOWGRADE)/GROUP + 1;    // grouped by GROUP

struct StudentType  {               // information of one student
    int grade;                       // the grade of the student
    char last[MAXLENGTH];            // last name (MAXLENGTH-1 at most)
    char first[MAXLENGTH];           // first name (MAXLENGTH-1 at most)
};
//-------------------------------------------------------------------------------
//swap function
template<typename T>
void swapValues(T &val1, T &val2) {
    T temp;
    temp = val2;
    val2 = val1;
    val1 = temp;
}
// prototypes go here
bool sortInput(istream &, StudentType [], int &);
void displayList(const StudentType [], int);
void setHistogram(int &arr,int histogram [], StudentType [], int);
void displayHistogram(int arr[]);
int findAverage(StudentType [], int);

//-----------------------------------------------------------------------------
int main()  {
   
    StudentType students[MAXSIZE];   // list of MAXSIZE number of students
    int size = 0;                    // total number of students
    int histogram[HISTOGRAMSIZE];    // grades grouped by GROUP
    int average = 0;                 // average exam score, truncated
    int arr[GROUP+1][3];
   
    ifstream infile("data1.txt");
    if (!infile)  {
        cout << "File could not be opened." << endl;
        return 1;
    }
   
    
    bool successfulRead = sortInput(infile, students, size);
    if (successfulRead)  {
        cout<<" List of names sorted:"<<endl;
        displayList(students, size);
        cout << endl;
        setHistogram(arr, histogram, students, size);
        cout << "Histogram of grades: " << endl;
        displayHistogram(); //any parameters ???
        average = findAverage(students, size);
        cout << endl << "Average grade: " << average << endl << endl;
    }
    infile.close(); //added code on 09/26
    return 0;
}
//-------------------------------------------------------------------------------
bool sortInput(istream &infile, StudentType students [], int &size)
{
    char temp[MAXLENGTH]; //try int if not working
    infile >> temp; //temp=infile.get();
    int circle=0;
   
    StudentType tempArray[1];
    char error[MAXLENGTH];
   
    while(size<MAXSIZE &&!infile.eof())
    {
        if(strcmp(temp, "error") != 0 && circle==0)
        {
            strcpy(students[size].last, temp);
            infile >> students[size].first >> students[size].grade;
            size++;
            circle++; //to make sure that we skip the first if statement next time
            infile >> temp;
        }
        else if(strcmp(temp, "error") != 0 && circle!=0)
        {
            strcpy(tempArray[0].last, temp);
            infile >> tempArray[0].first >> tempArray[0].grade;

            for(int i=size; i>=0; i--)
            {
                if(strcmp(tempArray[0].last, students[i-1].last)<0)
                {
                  strcpy(students[i].last, students[i-1].last);
                  strcpy(students[i].first, students[i-1].first);
                  students[i].grade=students[i-1].grade;
                }
                else if(strcmp(tempArray[0].last, students[i-1].last) == 0 &&
                        strcmp(tempArray[0].first, students[i-1].first)<0)
                {
                  strcpy(students[i].last, students[i-1].last);
                  strcpy(students[i].first, students[i-1].first);
                  students[i].grade=students[i-1].grade;
                }
                else{
                  strcpy(students[i].last, tempArray[0].last);
                  strcpy(students[i].first, tempArray[0].first);
                  students[i].grade=tempArray[0].grade;
                 
                    size++;
                    infile>>temp;
                    break;
                }
            } 
        }
        else{
            infile >> error >> error >> temp;
        }
    }
    return true;
}
//-----------------------------------------------------------------------------
void displayList(const StudentType students [], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<setw(4)<<students[i].grade<<"  "
        <<students[i].last<<"  "<<students[i].first<<endl;
    }
}

//-----------------------------------------------------------------------------
//int arr[GROUP+1][3];
void setHistogram(int &arr[], int histogram [], StudentType students [], int size)
{    
    int temp1=0;
    int temp2=9;
    int startFrame=0;
    int endFrame=10;
   
    for(int i=0; i<HISTOGRAMSIZE; i++)
    {
        arr[i][0]=temp1;
        arr[i][1]=temp2;     
        temp1+=10;
        temp2+=10;
       
        if(temp2>MAXGRADE){
            temp2=MAXGRADE;
        }
    }
    for(int a=0; a<HISTOGRAMSIZE; a++)
    {
        for(int b=0; b<=size; b++)
        {
          if(students[b].grade<endFrame && students[b].grade>=startFrame)
          {
            arr[a][2]+=1;
          }
        }
        startFrame+=10;
        endFrame+=10;
    }
}

//------------------------------------------------------------------------------
void displayHistogram(int arr[])
{
  for(int i=0; i<HISTOGRAMSIZE; i++)
  {
    cout<<setw(4)<<arr[i][0]<<" -->"<<setw(4)<<arr[i][1]<<": ";
    if(arr[i][2]!=0)
    {
      for(int star=0; star<arr[i][2]; star++)
      {
        cout<<"*"; //prints *
      }
    }
    cout<<endl;
    }
}

//------------------------------------------------------------------------------

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

// You must put a separator line between every function
// Then comes the name of the function on a separate comment line
// Then comes the function comment. Clearly comment every function.
// Use bubble.cpp
