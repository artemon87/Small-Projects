//
//  Sort.h
//  BubbleSort
//
//  Created by Artem Kovtunenko on 11/5/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

//#ifndef __BubbleSort__Sort__
//#define __BubbleSort__Sort__

#include <stdio.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

void InsertSort(vector<int> &vect,int low, int high);
void BubbleSort(vector<int> &vect,int low, int high);
void QuickSort(vector<int> &vect, int low, int high);
void IterativeMergeSort(vector<int> &vect, int low, int high);
void MergeSort(vector<int> &vect, int low, int high);
void merge(vector<int> &vect, int size, int low, int mid, int high);
void IterMerge(vector<int> &vect, vector<int> &temp, int low, int mid, int high);
int partition(vector<int> &vect, int low, int high);

void InsertSort(vector<int> &vect, int low, int high)
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
  int size=high-low+1;
  int temp;
  for(int m=size-1; m>0; m--)
  {
    for(int i=0; i<m; i++)
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
void MergeSort(vector<int> &vect, int low, int high)
{
  if(low<high)
  {
    int mid=(high+low)/2;
    MergeSort(vect, low, mid);
    MergeSort(vect, mid+1, high);
    merge(vect, high+1, low, mid, high);
  }
}
void merge(vector<int> &vect, int size, int low, int mid, int high)
{
  vector<int> temp(size);
  int first=low;
  int last=mid;
  int first2=mid+1;
  int last2=high;
  int firstNew=first;
  
  while(first<=last && first2<=last2)
  {
    if(vect[first]<=vect[first2])
    {
      temp[firstNew]=vect[first];
      first++;
    }
    else
    {
      temp[firstNew]=vect[first2];
      first2++;
    }
    firstNew++;
  }
  while(first<=last)
  {
    temp[firstNew]=vect[first];
    first++;
    firstNew++;
  }
  while(first2<=last2)
  {
    temp[firstNew]=vect[first2];
    first2++;
    firstNew++;
  }
  for (int i=low; i<=high; i++)
  {
    vect[i]=temp[i];
  }
}
void QuickSort (vector<int> & vect, int low, int high)
{
  if(high-low < 4)
  {
    InsertSort(vect, low, high);
  }
  else
  {
    int pivotIndex=partition(vect, low, high);
    QuickSort(vect, low, pivotIndex-1);
    QuickSort(vect, pivotIndex+1, high);
  }
}
int partition(vector<int> &vect, int low, int high)
{
  int mid=(low+high)/2;
  if(vect[low]>vect[mid])
  {
    swap(vect[low], vect[mid]);
  }
  if(vect[mid] > vect[high])
  {
    swap(vect[mid], vect[high]);
  }
  if(vect[low] > vect[mid])
  {
    swap(vect[low], vect[mid]);
  }
  
  swap(vect[mid], vect[high-1]);
  int pivotIndex=high-1;
  int pivot=vect[pivotIndex];
  int left=low+1;
  int right=high-2;
  bool done=false;
  
  while(!done)
  {
    while(vect[left]<pivot)
    {
      left++;
    }
    while(vect[right]>pivot)
    {
      right--;
    }
    if(left<=right)
    {
      swap(vect[left], vect[right]);
      right--;
      left++;
    }
    else
    {
      done=true;
    }
  }
  swap(vect[left], vect[high-1]);
  pivotIndex=left;
  return pivotIndex;
}

/*
 void QuickSort(vector<int> &vect, int low, int high)
 {
 int i=low;
 int j=high;
 int temp;
 int pivot=vect[(high+low)/2];
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
 QuickSort(vect, low, j);
 }
 if(i<high)
 {
 QuickSort(vect, i, high);
 }
 }*/
void IterativeMergeSort(vector<int> &vect, int low, int high)
{
  vector<int> temp(high+1);
  int i, j;
  for(i=1; i<high-low; i+=i)
  {
    for(j=high-i; j>=0; j-=i+i)
    {
      IterMerge(vect, temp, max(j-i+1, 0), j, j+i);
    }
  }
}
void IterMerge(vector<int> &vect, vector<int> &temp, int low, int mid, int high)
{
  int first=low;
  int last=mid;
  int first2=mid+1;
  int last2=high;
  
  int firstNew=first;
  
  while(first<=last && first2<=last2)
  {
    if(vect[first]<=vect[first2])
    {
      temp[firstNew]=vect[first];
      first++;
    }
    else
    {
      temp[firstNew]=vect[first2];
      first2++;
    }
    firstNew++;
  }
  while(first<=last)
  {
    temp[firstNew]=vect[first];
    first++;
    firstNew++;
  }
  while(first2<=last2)
  {
    temp[firstNew]=vect[first2];
    first2++;
    firstNew++;
  }
  for (int i=low; i<=high; i++)
  {
    vect[i]=temp[i];
  }
}


//#endif /* defined(__BubbleSort__Sort__) */
