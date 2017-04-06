#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include "Sort.h"

using namespace std;

int Search(int value, int first, int last, vector<int> &vect, int count);
void InsSort(vector<int> &vect,int low, int high);
void BubbleSort(vector<int> &vect,int low, int high);
void quickSort(vector<int> &vect, int low, int high);
void mergeSort(vector<int> &vect, int low, int high);
void merge(vector<int> &vect, int size, int low, int mid, int high);


int main()
{
    vector<int> vect;
    
    
    for(int i=0; i<10; i++)
    {
        vect.push_back(rand()%50+1);
        cout<<vect.at(i)<<" ";
    }
    cout<<endl;
    int size=int (vect.size());
    //InsSort(vect,0, size-1);
    //BubbleSort(vect,0, size-1);
    //mergeSort(vect, 0, size-1);
    quickSort(vect, 0, size-1);
    cout<<"After sorting"<<endl;
    for(int i=0; i<size; i++)
    {
        
        cout<<vect.at(i)<<" ";
    }
    cout<<endl;
    return 0;
    
}

/*void InsSort(vector<int> &vect, int low, int high)
{
    int j, temp;
    for (int i=1; i<high+1; i++)
    {
        j=i;
        while(j>0 && (vect[j]<vect[j-1]))
        {
            temp=vect[j];
            vect[j]=vect[j-1];
            vect[j-1]=temp;
            j--;
        }
    }
}
void BubbleSort(vector<int> &vect,int low, int high)
{
    int temp;
    for(int m=high; m>0; m--)
    {
        for(int i=0; i<high; i++)
        {
            if(vect[i]>vect[i+1])
            {
                temp=vect[i+1];
                vect[i+1]=vect[i];
                vect[i]=temp;
                
            }
        }
    }
}
void mergeSort(vector<int> &vect, int low, int high)
{
  //int size=10;//vect.size();
  if(low<high)
  {
      int mid=low+(high-low)/2; //=(high+low)/2;
      mergeSort(vect, low, mid);
      mergeSort(vect, mid+1, high);
      merge(vect, high+1, low, mid, high);
  }
}
void merge(vector<int> &vect, int size, int low, int mid, int high)
{
  vector<int> temp(size);
  for (int i=low; i<=high; i++)
  {
      temp[i]=vect[i];   //.push_back[i]
  }
  int a=low;
  int b=mid+1;
  int c=low;
  while(a<=mid && b<=high)
  {
      if(temp[a]<+temp[b])
      {
          vect[c]=temp[a];
          a++;
      }
      else
      {
          vect[c]=temp[b];
          b++;
      }
      c++;
  }
  while(a<=mid)
  {
      vect[c]=temp[a];
      a++;
      c++;
  }
}
void quickSort(vector<int> &vect, int low, int high)
{
  int i=low;
  int j=high;
  int temp;
  int pivot=vect[low+(high-low)/2];
  while(i<=j)
  {
    while(vect[i]<pivot)
    {
      i++;
    }
    while(vect[j]>pivot)
    {
      j--;
    }
    if(i<=j)
    {
      temp=vect[i];
      vect[i]=vect[j];
      vect[j]=temp;
      i++; j--;
    }
  }
  if(low<j)
  {
    quickSort(vect, low, j);
  }
  else if(i<high)
  {
    quickSort(vect, i, high);
  }
  
}
*/