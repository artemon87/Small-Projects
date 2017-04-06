//
//  Sort.cpp
//  BubbleSort
//
//  Created by Artem Kovtunenko on 11/5/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include "Sort.h"
#include <algorithm>


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
    //int size=10;//vect.size();
    if(low<high)
    {
        int mid=low+(high-low)/2; //=(high+low)/2;
        MergeSort(vect, low, mid);
        MergeSort(vect, mid+1, high);
        merge(vect, high+1, low, mid, high);
    }
}
void merge(vector<int> &vect, int size, int low, int mid, int high)
{
    vector<int> temp(size);
    //cout<<"Size is "<<size<<endl;
    //for (int i=low; i<=high; i++)
    //{
    //    temp[i]=vect[i];
    //}
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
}
/*void OtherMerge(vector<int> &vect, int low, int high)
{
    int lowest, highest, mid;
    int temp=0;
    //for(int index=0; index<high; index+=2)
    //{
     //  if(vect[index]>vect[index+1])
     //  {
     //      swap(vect[index], vect[index+1]);
     //  }
   // }
    for(int i=1; i<=high+1; i=2*i)
    {
        for(int j=0; j<(high+1); j+=i)
        {
            temp=i;
            lowest=j;
            if((j+i-1)<=high)
            {
                highest=j+i-1;
            }
            else
            {
                highest=high;
            }
            //highest=j+2*i;
            mid=(highest+lowest)/2;
            merge(vect, high+1, lowest, mid, highest);
            
        }
    }
    if((high+1)%(temp/2)!=0)
    {
        int s=high-(high+1)%(temp/2);
        cout<<"S= "<<s<<endl;
        merge(vect, high+1, 0, s, high);
    }
    //merge(vect, high+1, 0, , high);
    //cout<<"Temp1 "<<temp1<<" and temp2 "<<temp2<<endl;
    //cout<<"MID is: "<<mid<<endl;
    //cout<<"Highest is: "<<highest<<endl;
    //cout<<"Lowest : "<<lowest<<endl;
    //1q        cout<<"Temp "<<temp<<endl;
    //cout<<temp<<" "<< temp+(temp/2)<<" "<<highest+1<<endl;
    //int temp=
    //merge(vect, high+1, temp, temp+(temp/2), highest+1);
    //merge(vect, high+1, low, mid, high);
        
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

