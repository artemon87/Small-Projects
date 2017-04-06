#ifndef __LinkedL_342___List342__

#define __LinkedL_342___List342__


#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Child.h"
#include "Bird.h"


using namespace std;


template <class ItemType>
struct Node
{
  ItemType value;
  Node<ItemType> *next=NULL;
};



template<class ItemType>
class List342 //:  public Child
{
  
private:
  
  Node<ItemType> *head;
  
public:

  List342();
  List342(const List342<ItemType> &source);
  ~List342();
  
  bool Remove(ItemType, ItemType&);
  void Insert(ItemType *a);
  bool Merge(List342<ItemType> &, List342<ItemType> &);
  bool Peek(ItemType, ItemType &);
  bool operator!=(const List342<ItemType> & source)const;
  bool operator==(const List342<ItemType> &source)const;
  bool operator=(const List342<ItemType> &source);
  List342 operator+(const List342<ItemType> &source)const;
  List342 operator+=(const List342<ItemType> &source);
  bool BuildList(string fileName);
  bool isEmpty();
  void ClearList();
  
  friend ostream& operator<<(ostream & out, const List342<ItemType> & stack)
  {
    Node<ItemType> *pNode=stack.head;
    while(pNode!=NULL)
    {
      out<<pNode->value;
      pNode=pNode->next;
    }
    return out;
  }
};


#endif /* defined(__LinkedL_332___IntStack__) */


  
template<class ItemType>
List342<ItemType>:: List342()
  {
    head=NULL;
  }
///////////////////////////////////////////////////////////////////////////
template<class ItemType>
List342<ItemType>::~List342()
{
  this->ClearList(); ///////////////
}
///////////////////////////////////////////////////////////////////////////
template<class ItemType>
List342<ItemType>:: List342(const List342<ItemType> &source)
{
  this->head=NULL;
  *this=source;
}
/////////////////////////////////////////////////////////////////////////
template<class ItemType>
bool List342<ItemType>:: Remove(ItemType target, ItemType &result)
  {
    Node <ItemType> *pTarget;
    Node<ItemType> *pTemp;
    pTarget=this->head;
    if(head==NULL)
    {
      return false;
    }
    else if(head->value==target)
    {
      result=target;
      pTarget=head->next;
      delete head;
      head=pTarget;
      return true;
    }
    else
    {
      while(pTarget->value!=target && pTarget!=NULL)
      {
        pTemp=pTarget;
        pTarget=pTarget->next;
      }
      if(pTarget->value==target)
      {
        result=target;
        pTemp->next=pTarget->next;
        
        //head->next=pTemp;//pTarget->next;
        delete pTarget;
        //head=pTemp;
        return true;
      }
    }
    return false;
    
    
  }
////////////////////////////////////////////////////////////////////////////////
template<class ItemType>
bool List342<ItemType>:: Peek(ItemType target, ItemType &result)
{
  Node<ItemType> *pTarget;
  Node<ItemType> *pTemp;
  pTarget=this->head;
  if(head==NULL)
  {
    return false;
  }
  else if(head->value==target)
  {
    result=target;
    pTarget=head->next;
    delete head;
    head=pTarget;
    return true;
  }
  else
  {
    while(pTarget->value!=target && pTarget!=NULL)
    {
      pTemp=pTarget;
      pTarget=pTarget->next;
    }
    if(pTarget->value==target)
    {
      result=target;
      return true;
    }
  }
  return false;
}
///////////////////////////////////////////////////////////////////////////////
template<class ItemType>
void List342<ItemType>:: Insert(ItemType *a)
{
  Node<ItemType> *newNode=new Node<ItemType>;
  newNode->value=*a;//child;
  Node<ItemType> *temp=head;
  if(head==NULL || (newNode->value <= temp->value))
  {
    newNode->next=head;
    head=newNode;
    //itemCount++;
  }
  else
  {
    while(temp->next!=NULL && (temp->next->value <= newNode->value))
    {
      temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
  }
}
//////////////////////////////////////////////////////////////////////////////
template<class ItemType>
bool List342<ItemType>:: Merge(List342<ItemType> &list1, List342<ItemType> &list2)
{
  Node<ItemType> *list1Copy=list1.head;
  Node<ItemType> *list2Copy=list2.head;
  Node<ItemType> *thisNode=this->head;
  Node<ItemType> *temp;
  Node<ItemType> *mergeNode;
  
  if(list1Copy==NULL && list2Copy==NULL)
  {
    return true;
  }
  else if(list1Copy==thisNode && list2Copy==thisNode)
  {
    return true;
  }
  else if(thisNode==NULL && list2Copy==list1Copy)
  {
    this->head=list1Copy;
    list1.head=NULL;
    list2.head=NULL;
  }
  else if((list1Copy==NULL && thisNode!=NULL && thisNode!=list2Copy) ||
         (list1Copy==thisNode && thisNode!=NULL && thisNode!=list2Copy))
  {
    if(list2Copy->value<thisNode->value)
    {
      mergeNode=list2Copy;
    }
    else
    {
      mergeNode=thisNode;
      thisNode=list2Copy;
      list2Copy=mergeNode;
    }
    while(list2Copy->next!=NULL && thisNode!=NULL)
    {
      if(list2Copy->next->value < thisNode->value)
      {
        list2Copy=list2Copy->next;
      }
      else
      {
        temp=list2Copy->next;
        list2Copy->next=thisNode;
        thisNode=temp;
      }
    }
    if(list2Copy->next==NULL)
    {
      list2Copy->next=thisNode;
    }
    this->head=mergeNode;
    list2.head=NULL;
    return true;
  }
  else if(list1Copy==NULL && thisNode==NULL)
  {
    this->head=list2Copy;
    if(list2Copy!=thisNode)
    {
      list2.head=NULL;
    }
    return true;
  }
  else if((list1Copy==NULL & thisNode==list2Copy) ||
          (list2Copy==NULL && thisNode==list1Copy))
  {
    return true;
  }
  else if((list2Copy==NULL && thisNode!=NULL && thisNode!=list1Copy) ||
         (list2Copy==thisNode && thisNode!=NULL && thisNode!=list1Copy))
  {
    if(list1Copy->value<thisNode->value)
    {
      mergeNode=list1Copy;
    }
    else
    {
      mergeNode=thisNode;
      thisNode=list1Copy;
      list1Copy=mergeNode;
    }
    while(list1Copy->next!=NULL && thisNode!=NULL)
    {
      if(list1Copy->next->value < thisNode->value)
      {
        list1Copy=list1Copy->next;
      }
      else
      {
        temp=list1Copy->next;
        list1Copy->next=thisNode;
        thisNode=temp;
      }
    }
    if(list1Copy->next==NULL)
    {
      list1Copy->next=thisNode;
    }
    this->head=mergeNode;
    list1.head=NULL;
    return true;
  }
  else if(list2Copy==NULL && thisNode==NULL)
  {
    this->head=list1Copy;
    if(list1Copy!=thisNode)
    {
      list1.head=NULL;
    }
    return true;
  }
  else if(thisNode==NULL && list1Copy!=list2Copy)
  {
    if(list1Copy->value<list2Copy->value)
    {
      mergeNode=list1Copy;
    }
    else
    {
      mergeNode=list2Copy;
      list2Copy=list1Copy;
      list1Copy=mergeNode;
    }
    while(list1Copy->next!=NULL && list2Copy!=NULL)
    {
      if(list1Copy->next->value < list2Copy->value)
      {
        list1Copy=list1Copy->next;
      }
      else
      {
        temp=list1Copy->next;
        list1Copy->next=list2Copy;
        list2Copy=temp;
      }
    }
    if(list1Copy->next==NULL)
    {
      list1Copy->next=list2Copy;
    }
    this->head=mergeNode;
    list1.head=NULL;
    list2.head=NULL;
    return true;
  }
  else
  {
    if(list1Copy->value <= list2Copy->value && list1Copy->value <= thisNode->value)
    {
      mergeNode=list1Copy;
    }
    else if(list1Copy->value <= list2Copy->value && list1Copy->value > thisNode->value)
    {
      mergeNode=thisNode;
      thisNode=list1Copy;
      list1Copy=mergeNode;
    }
    else if(list1Copy->value>list2Copy->value && list2Copy->value <= thisNode->value)
    {
      mergeNode=list2Copy;
      list2Copy=list1Copy;
      list1Copy=mergeNode;
    }
    else
    {
      mergeNode=thisNode;
      thisNode=list1Copy;
      list1Copy=mergeNode;
    }
    while(list1Copy->next!=NULL && list2Copy!=NULL && thisNode!=NULL)
    {
      if(list1Copy->next->value <=list2Copy->value && list1Copy->next->value<=thisNode->value)
      {
        list1Copy=list1Copy->next;
      }
      else if(list1Copy->next->value <=list2Copy->value && list1Copy->next->value>thisNode->value)
      {
        temp=list1Copy->next;
        list1Copy->next=thisNode;
        thisNode=temp;
      }
      else if(list1Copy->next->value > list2Copy->value && list2Copy->value<=thisNode->value)
      {
        temp=list1Copy->next;
        list1Copy->next=list2Copy;
        list2Copy=temp;
      }
      else
      {
        temp=list1Copy->next;
        list1Copy->next=thisNode;
        thisNode=temp;
      }
    }
    if(list1Copy->next==NULL && list2Copy->value<=thisNode->value)
    {
      list1Copy->next=list2Copy;
      while(list2Copy->next!=NULL && thisNode!=NULL)
      {
        if(list2Copy->next->value<=thisNode->value)
        {
          list2Copy=list2Copy->next;
        }
        else
        {
          temp=list2Copy->next;
          list2Copy->next=thisNode;
          thisNode=temp;
        }
      }
      if(list2Copy->next==NULL)
      {
        list2Copy->next=thisNode;
      }
      this->head=mergeNode;
      list1.head=NULL;
      list2.head=NULL;
      return true;
    }
    else if(list1Copy->next==NULL && list2Copy->value>thisNode->value)
    {
      list1Copy->next=thisNode;
      while(thisNode->next!=NULL && list2Copy!=NULL)
      {
        if(thisNode->next->value<=list2Copy->value)
        {
          thisNode=thisNode->next;
        }
        else
        {
          temp=thisNode->next;
          thisNode->next=list2Copy;
          list2Copy=temp;
        }
      }
      if(thisNode->next==NULL)
      {
        thisNode->next=list2Copy;
      }
      this->head=mergeNode;
      list1.head=NULL;
      list2.head=NULL;
      return true;
    }
  }
  return true;
}
//////////////////////////////////////////////////////////
template<class ItemType>
bool List342<ItemType>:: operator!=(const List342<ItemType> & list1)const
  {
  Node<ItemType> *node1=this->head;
  Node<ItemType> *node2=list1.head;
  if(node1==NULL && node2==NULL)
  {
    return false;
  }
  else if((node1==NULL && node2!=NULL) ||
          (node1!=NULL && node2==NULL))
  {
    return true;
  }
  while(node1->next!=NULL && node2->next!=NULL)
  {
    if(node1->value == node2->value)
    {
      node1=node1->next;
      node2=node2->next;
    }
    else
    {
      return true;
    }
  }
  if((node1->next==NULL && node2->next!=NULL) ||
    (node2->next==NULL && node1->next!=NULL))
    {
      return true;
    }
  else if(node1->value == node2->value)
  {
    return false;
  }
  return true;
}
///////////////////////////////////////////////////////////
template<class ItemType>
bool List342<ItemType>:: operator==(const List342<ItemType> &list1)const
  {
    Node<ItemType> *node1=list1.head;
    Node<ItemType> *node2=this->head;
    if(node1==NULL && node2==NULL)
    {
      return true;
    }
    while(node1->next!=NULL && node2->next!=NULL)
    {
      if(node1->value == node2->value)
      {
        node1=node1->next;
        node2=node2->next;
      }
      else
      {
        return false;
      }
      //return true;
    }
    if(node1->value == node2->value)
    {
      return true;
    }
    return false;
  }
//////////////////////////////////////////////////////
template<class ItemType>
bool List342<ItemType>:: operator=(const List342<ItemType> &source)
{
  //int x;
  while(this->head!=NULL)
  {
    //Pop(x);
    ClearList();
  }
  Node<ItemType> *newNodeP=source.head;
  while(newNodeP!=NULL)
  {
    Insert(&newNodeP->value);
    newNodeP=newNodeP->next;
  }
  //this->head=newNodeP;
  return true;
}
///////////////////////////////////////////////////////
template<class ItemType>
bool List342<ItemType>:: isEmpty()
{
  return (this->head);
}
/////////////////////////////////////////////////////////
template<class ItemType>
void List342<ItemType>:: ClearList()
{
   Node<ItemType> *temp=this->head;
   while(temp!=NULL)
   {
     this->head=this->head->next;
     delete temp;
     temp=this->head;
   }
   this->head=NULL;
}
////////////////////////////////////////////////////////////
template<class ItemType>
List342<ItemType> List342<ItemType>:: operator+(const List342 <ItemType> &list2)const
{
  List342<ItemType> output;
  Node<ItemType> *rightP=this->head;
  Node<ItemType> *leftP=list2.head;
  if(rightP==NULL && leftP==NULL)
  {
    return output;
  }
  else if(rightP==NULL)
  {
    return list2;
  }
  else if(leftP==NULL)
  {
    return *this;
  }
  while(rightP->next!=NULL)
  {
    output.Insert(&(rightP->value));
    rightP=rightP->next;
  }
  output.Insert(&(rightP->value));
  while (leftP->next!=NULL)
  {
    output.Insert(&(leftP->value));
    leftP=leftP->next;
  }
  output.Insert(&(leftP->value));
  return output;
}
///////////////////////////////////////////////////////////
template<class ItemType>
List342<ItemType> List342<ItemType>:: operator+=(const List342<ItemType> &list2)
{
  Node<ItemType> *leftP=this->head;
  Node<ItemType> *rightP=list2.head;
  if(leftP==NULL && rightP==NULL)
  {
    return *this;
  }
  else if(leftP==NULL)
  {
    cout<<"Left point is NULL"<<endl;
    return list2;
  }
  else if(rightP==NULL)
  {
    cout<<"Right point is NULL"<<endl;
    return *this;
  }
  while(rightP->next!=NULL)
  {
    this->Insert(&(rightP->value));
    rightP=rightP->next;
  }
  this->Insert(&(rightP->value));
  
  return *this;
}
///////////////////////////////////////////////////////////
template<class ItemType>
bool List342<ItemType>:: BuildList(string fileName)
{
  List342<ItemType> newStack;
  ItemType line;
  ifstream inFile;
  inFile.open(fileName.c_str());
  if(!inFile)
  {
    cout<<"File cannot be opened"<<endl;
    return false;
  }
  else
  {
    while(!inFile.eof())
    {
      inFile>>line;
      newStack.Insert(&line);
    }
  }
  *this=newStack;
  return true;
}