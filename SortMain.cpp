#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <windows.h>
#include "SortImpls.h"

using namespace std;

//int Search(int value, int first, int last, vector<int> &vect, int count);
//void InsSort(vector<int> &vect,int low, int high);
//void BubbleSort(vector<int> &vect,int low, int high);
//void quickSort(vector<int> &vect, int low, int high);
//void mergeSort(vector<int> &vect, int low, int high);
//void merge(vector<int> &vect, int size, int low, int mid, int high);



int main()
{
  vector<int> vect;
  bool copy=false;
  int n=20;
  //InitArray(vect, size);
  for(int i=0; i<n; i++)
  {
      vect.push_back(i);
  }
  for(int i=0; i<vect.size()-1; i++)
  {
    int r=rand()%n;
    int temp=vect[i];
    vect[i]=vect[r];
    vect[r]=temp;
    //cout<<vect.at(i)<<" ";
  }
  for (int i=0; i<n; i++)
  {
    cout<<vect.at(i)<<" ";
  }
  
  cout<<endl;
  int size=int (vect.size());

  //clock_t timeStart, timeEnd;

  //BubbleSort(vect,0, size-1);
  //MergeSort(vect, 0, size-1);
  //timeEnd=clock();
  //MergeSort(vect, 0, size-1);
  //timeStart=clock();
  int begin=GetTickCount();
  //InsertSort(vect, 0, size-1);
  //MergeSort(vect, 0, size-1);
  IterativeMergeSort(vect, 0, size-1);
  //BubbleSort(vect,0, size-1);
  //QuickSort(vect, 0, size-1);
  int end=GetTickCount();
 // timeEnd=clock();
  double time=end-begin;
  //cout<<"Time: "<<time<<endl;
  //quickSort(vect, 0, size-1);
  cout<<"This is an ItertiveMergeSort"<<endl;
  cout<<"After sorting"<<endl;
  for(int i=0; i<size; i++)
  {   
      cout<<vect.at(i)<<" ";
  }
  cout<<endl;
  cout<<"Time: "<<time<<endl;
  return 0;
  
}

/*
 void InsSort(vector<int> &vect, int low, int high);
 void PrinArray(const vector<int> &array, string name);
 void InitArray(vector<int> &array, int randMax);
 int main(int argc, char* argv[])
 {
  if (argc != 3)
  {
    cout << "Usage: Sorter SORT_TYPE ARRAY_SIZE";
    return -1;
  }
 string sort_name = string(argv[1]);
 int size = atoi(argv[2]);
 if (size <= 0) {
 cerr << "array size must be positive" << endl;
 return -1;
 }
 srand(1);
 vector<int> items(size);
 InitArray(items, size);
 cout << "Sort employed: " << sort_name << endl;
 cout << "initial:" << endl;
 PrinArray(items, string("items"));
 // GetTickCount is windows specific.
 // For linux use gettimeofday. As shown::
 // struct timeval startTime, endTime;
 // gettimeofday(&startTime, 0);
 clock_t begin = clock();// Place logic to determine and call function of interest here.
 // Do not call all of them
 MergeSort(items, 0, size - 1);
 //IterativeMergeSort(items, 0, size - 1);
 //QuickSort(items, 0, size - 1);
 //BubbleSort(items, 0, size - 1);
 //InsertSort(items, 0, size - 1);
 clock_t end = clock();
 // Linux timer:
 // gettimeofday(&endTime, 0);
 cout << "sorted:" << endl;
 PrinArray(items, string("item"));
 clock_t elapsed_secs = end - begin;
 cout << "Time (ms): " << elapsed_secs << endl;
 return 0;
 }
 // array initialization with random numbers
 void InitArray(vector<int> &array, int randMax)
 {
   int size = int(array.size());
   for (int i = 0; i < size;)
   {
     int tmp = (randMax == -1) ? rand() : rand() % randMax;
     bool hit = false;
   for (int j = 0; j < i; j++)
   {
     if (array[j] == tmp)
   {
   hit = true;
   break;
   }
   }
   if (hit)
   {
     continue;
   }
   array[i] = tmp;
   i++;
   }
 }
void PrinArray(const vector<int> &array, string name)
{
  int size = int(array.size());
  for (int i = 0; i < size; i++)
    cout << name << "[" << i << "] = " << array[i] << endl;
}
*/
