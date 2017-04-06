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

/*struct StructForHistogram
 {
 int start;
 int end;
 char star;
 
 };*/
//StructForHistogram histogram[HISTOGRAMSIZE];
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
//void bubbleSort(StudentType [], int);
void displayList(const StudentType [], int);
void setHistogram(int histogram [], StudentType [], int);
void displayHistogram();
int findAverage(StudentType [], int);

//-----------------------------------------------------------------------------
int main()  {
    //StructForHistogram histogram[HISTOGRAMSIZE];
    StudentType students[MAXSIZE];   // list of MAXSIZE number of students
    int size = 0;                    // total number of students
    int histogram[HISTOGRAMSIZE];    // grades grouped by GROUP
    int average = 0;                 // average exam score, truncated
   
    ///////////////////////////////////
    //StructForHistogram histogram[HISTOGRAMSIZE];
    //////////////////////////////////////////
   
    // creates file object and opens the data file
    ifstream infile("data1.txt");
    if (!infile)  {
        cout << "File could not be opened." << endl;
        return 1;
    }
   
    // read and sort input by last then first name
    bool successfulRead = sortInput(infile, students, size);
   
    // display list, histogram, and class average
    if (successfulRead)  {
        //bubbleSort(students, size);
       
        displayList(students, size);
        setHistogram(histogram, students, size);
        displayHistogram(); //any parameters ???
        average = findAverage(students, size);
        cout << "Average grade: " << average << endl << endl;
    }
    infile.close(); //added code on 09/26
    return 0;
}

// ----------------------------------------------------------------------------
// functions go here

/*bool sortInput(istream &infile, StudentType students [], int &size)
 {
 char temp[MAXLENGTH]; //try int if not working
 infile >> temp; //temp=infile.get();
 
 char error[MAXLENGTH];
 // char error='error';
 //if(strcmp(temp, "error")==0){}
 //strcpy(error, "error");
 
 //cout<<"Infile: "<<infile<<endl;
 //cout<<temp<<endl;
 //if(temp=='error')
 //{
 while(size<MAXSIZE &&!infile.eof())
 {
 if(strcmp(temp, "error") != 0)
 {
 strcpy(students[size].last, temp);
 infile >> students[size].first >> students[size].grade;
 size++;
 cout<<"Before: "<<temp<<endl;
 //cout<<"Before grade: "<<students[size].grade<<endl;
 
 infile >> temp;
 }
 else{
 
 infile>>error;
 cout<<error<<" ";
infile>>error;
 cout<<error<<" ";
 infile>>temp;
 cout<<error<<" ";
 
 cout<<"IGNORE"<<endl;}
 
 //cout<<"After: "<<temp<<endl;
 //cout<<"After grade: "<<students[size].grade<<endl;
 }
 cout<<"Current SIZE: "<<size<<endl;
 return true;
 // }
 }*/

//-------------------------------------------------------------------------------
bool sortInput(istream &infile, StudentType students [], int &size)
{
    char temp[MAXLENGTH]; //try int if not working
    infile >> temp; //temp=infile.get();
    int circle=0;
   
    StudentType tempArray[1];
   bool NLG=false;
    char error[MAXLENGTH];
   
    while(size<1000 &&!infile.eof())
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
            //size++;
            //cout<<"Students: "<<students[size-1].last<<" "<<students[size-1].first<<" "<<students[size-1].grade<<" : "<<size-1<<endl;
            //cout<<" TempArray size=0: "<<tempArray[size].last<<" "<<tempArray[size].first<<" "<<tempArray[size].grade<<endl;
           
           
            for(int i=size; i>=0; i--)
            {
                //cout<<"Size= "<<size<<endl;
                if(tempArray[0].grade<students[i-1].grade ||
                   (tempArray[0].grade==students[i-1].grade &&
                    tempArray[0].last<students[i-1].last))   //strcmp(students[size-1].grade, students[size]
                {
                    cout<<"Student i grade: "<<students[i].grade<<endl;
                    cout<<"Student i-1 grade: "<<students[i-1].grade<<endl;
                    strcpy(students[i].last, students[i-1].last);
                    strcpy(students[i].first, students[i-1].first);
                    students[i].grade=students[i-1].grade;
                }
                else if(tempArray[0].grade==students[i-1].grade &&
                        strcmp(tempArray[0].last, students[i-1].last) == 0 &&
                        tempArray[0].first<students[i-1].first)
                {
                    strcpy(students[size].last, students[i-1].last);
                    strcpy(students[size].first, students[i-1].first);
                    students[size].grade=students[i-1].grade;
                }
                else{
                    strcpy(students[i].last, tempArray[0].last);
                    strcpy(students[i].first, tempArray[0].first);
                    students[i].grade=tempArray[0].grade;
                   
                    //cout<<"Students B: "<<students[size-1].last<<" "<<students[size-1].first<<" "<<students[size-1].grade<<" : "<<size-1<<endl;
                    //cout<<"Students A: "<<students[size].last<<" "<<students[size].first<<" "<<students[size].grade<<" : "<<size-1<<endl;
                    //cout<<tempArray[size].last<<" "<<tempArray[size].first<<" "<<tempArray[size].grade<<endl;
                    //cout<<"Check it out" <<students[size].last<<"  "<<students[size].first<< " "<<students[size].grade<<endl;
                    size++;
                    infile>>temp;
                   
                    NLG=true;
                    break;
                }
                //start loop again
            } //closing for loop
            if(!NLG){
                strcpy(students[size].last, tempArray[0].last);
                strcpy(students[size].first, tempArray[0].first);
                students[size].grade=tempArray[0].grade;
                size++;
                infile>>temp;
                NLG=false;
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
int arr[GROUP+1][3];
void setHistogram(int histogram [], StudentType students [], int size)
{
    //StructForHistogram histogram[HISTOGRAMSIZE];
     cout<<"Grades of all students "<<students[0].grade<<" "<<endl;
     cout<<"Grades of all students "<<students[1].grade<<" "<<endl;
     cout<<"Grades of all students "<<students[2].grade<<" "<<endl;
     cout<<"Grades of all students "<<students[3].grade<<" "<<endl;
     cout<<"Grades of all students "<<students[4].grade<<" "<<endl;
     cout<<"Grades of all students "<<students[5].grade<<" "<<endl;
     cout<<"Grades of all students "<<students[6].grade<<" "<<endl;
     cout<<"Grades of all students "<<students[7].grade<<" "<<endl;
     cout<<size;
    
    int temp1=0;
    int temp2=9;
    int startFrame=0;
    int endFrame=10;
   
    for(int i=0; i<HISTOGRAMSIZE; i++)
    {
        arr[i][0]=temp1;
        arr[i][1]=temp2;
        //cout<<";;;;;;;;;;;;;;;;;;;;;;"<<endl;
        //histogram[i].start=temp1;
        // histogram[i].end=temp2;
        //cout<<histogram[0].end<<"----------------"<<endl;
       
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
            //cout<<"Grades of all students"<<students[a].grade<<" "<<endl;
            //cout<<size<<endl;
            if(students[b].grade<endFrame && students[b].grade>=startFrame)
            {
                //cout<<"Grades of all students"<<students[a].grade<<" "<<endl;
                arr[a][2]+=1;
                //cout<<arr[b][2]<<endl;
                //cout<<students[b].grade<<endl;
                //cout<<"    "<<students[a].grade<<endl;
                //histogram[a].star='*';
            }
            //cout<<"Grades of all students"<<students[a].grade<<" "<<endl;
            //ten+=10;
        }
       // cout<<"SIZE again: "<<size<<endl;
        //cout<<
        startFrame+=10;
        endFrame+=10;
    }
    //int val=arr[0][2];
    // cout<<val<<endl;
    //val=arr[1][2];
    // cout<<val<<endl;
    //  val=arr[2][2];
    // cout<<val<<endl;
    // val=arr[3][2];
    // cout<<val<<endl;
    // val=arr[4][2];
    // cout<<val<<endl;
    // val=arr[5][2];
    // cout<<val<<endl;
    // val=arr[6][2];
    // cout<<val<<endl;
    // val=arr[7][2];
    // cout<<val<<endl;
    //val=arr[8][2];
    //cout<<val<<endl;
}

//------------------------------------------------------------------------------
void displayHistogram()
{
   
    //cout<<arr[5][2]<<endl;
    //cout<<arr[6][2]<<endl;
    //cout<<arr[7][2]<<endl;
    //cout<<arr[0][2]<<endl;
   
    for(int i=0; i<HISTOGRAMSIZE; i++)
    {
        cout<<setw(4)<<arr[i][0]<<" -->"<<setw(4)<<arr[i][1]<<": ";
        if(arr[i][2]!=0)
        {
            for(int star=0; star<arr[i][2]; star++)//cout<<" * ";
            {
                cout<<"*";
            }
        }
        /*if(arr[i][2]==1)
         {
         cout<<" * ";
         //cout<<endl;
         }
         else if(arr[i][2]==2)
        {
         cout<<" ** ";
         //cout<<endl;
         }*/
        cout<<endl;
        //cout<<setw(4)<<histogram[i].start<<" --> "
        //     <<histogram[i].end<<": "
        //    <<histogram[i].star<<endl;
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
    //cout<<"Average grade: "<<sum/size<<endl;
    return sum/size;
}

// You must put a separator line between every function
// Then comes the name of the function on a separate comment line
// Then comes the function comment. Clearly comment every function.
// Use bubble.cpp
