//

//  IntStack.h

//  LinkedL(332)

//

//  Created by Artem Kovtunenko on 10/17/14.

//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.

//


#ifndef __LinkedL_332___IntStack__

#define __LinkedL_332___IntStack__


#include <stdio.h>

#include <iostream>

#include <string>

#include <fstream>

#include <iomanip>
#include "Child.h"
#include "Bird.h"


using namespace std;



/*template<class ItemType>

 struct NodeType{

 ItemType* item;

 NodeType* next;*/



/*class Bird

{

private:

  string birdName;

  int idNum;

  bool present;



public:

  Bird()

  {  }

  Bird(string name, int num)

  {

    present=true;

    birdName=name;

    idNum=num;

  }

  void setBirdName(string name)

  {

    birdName=name;

  }

  void setID(int num)

  {

    idNum=num;

  }

  string getName()const

  {

    return birdName;

  }

  int getID()const

  {

    return idNum;

  }

  Bird(const Bird &source)//copy constructor

  {

    cout<<"Copy constructor"<<endl;



  }

  void operator=(Bird &source)

  {

    if(this==&source)return;///????????? if you are calling yourself return false



    this->present=source.present;

    this->birdName=source.birdName;

    this->idNum=source.idNum;

  }




};*/


/*class Child//: public IntStack<Child>

{

private:

  string lastName;

  string firstName;

  int age;

public:



  //friend class IntStack<>;

  Child()

  {



  }

  Child(string lName, string fName, int years)

  {

    lastName=lName;

    firstName=fName;

    age=years;

  }

  void setLName(string lName)

  {

    lastName=lName;

  }

  void setFName(string fName)

  {

    firstName=fName;

  }

  void setAge(int age)

  {

    this->age=age;

  }

  string getLName()const

  {

    return lastName;

  }

  string getFName()const

  {

    return firstName;

  }

  int getAge()const

  {

    return age;

  }

  //Child readFile(string FileName)

  // {

  // ifstream file;

  // file.open(FileName);

  // while(



  //    file.close();

  // }

};*/


template <class ItemType>

struct Node

{

  ItemType value;

  Node<ItemType> *next=NULL;

};


//class Child;

template<class ItemType>

class IntStack //:  public Child

{

public:



  //friend Child;//<ItemType>

  //template<class ItemType>

  IntStack()

  {

    head=NULL;

  }

  ~IntStack()

  {

     this->clearList(); ///////////////

  }

  bool  Remove(ItemType target, ItemType &result)

  {
    Node <ItemType> *pTarget;
    Node<ItemType> *pTemp;
    pTarget=this->head;
    if(head==NULL)
    {
      return false;
    }
    while(pTarget->value!=target)//pTarget->value.getLName() != target.getLName()
          //&& pTarget->value.getFName() != target.getFName()
          //&& pTarget->value.getAge() != target.getAge()
          //&& pTarget->next != NULL)
    {
      pTemp=pTarget;
      pTarget=pTarget->next;
    }
    if(pTarget->value==target)
    {

      result=target;
      //cout<<"QQQQQ "<<result.getLName()<<endl;
      //cout<<"QQQQQ "<<result.getFName()<<endl;
      pTemp->next=pTarget->next;

      head=pTarget->next;
      delete head;
      head=pTarget;
      return true;
    }
    else
    {
      return false;
    }
  }
  /*bool  Remove(Bird target, Bird &result)

  {
    Node <Bird> *pTarget;
    pTarget=this->head;
    if(head==NULL)
    {
      return false;
    }
    while(pTarget->value.getName() != target.getName()
          && pTarget->value.getID() != target.getID()
          && pTarget->next != NULL)
    {
      pTarget=pTarget->next;
    }
    if(pTarget->value.getName()==target.getName())
    {
      result=target;
      head=pTarget->next;
      delete head;
      head=pTarget;
      return true;
    }
    else
    {
      return false;
    }
  }*/
  bool Peek(ItemType target, ItemType &result)
  {
    Node <ItemType> *pTarget;
    pTarget=this->head;
    if(head==NULL)
    {
      return false;
    }
    while(pTarget->value.getLName() != target.getLName()
          && pTarget->value.getFName() != target.getFName()
          && pTarget->value.getAge() != target.getAge()
          && pTarget->next != NULL)
    {
      pTarget=pTarget->next;
    }
    if(pTarget->value.getLName()==target.getLName())
    {
      result=target;
      //head=pTarget->next;
      //delete head;
      //head=pTarget;
      return true;
    }
    else
    {
      return false;
    }
  }
  bool Peek(Bird target, Bird &result)
  {
    Node <Bird> *pTarget;
    pTarget=this->head;
    if(head==NULL)
    {
      return false;
    }
    while(pTarget->value.getName() != target.getName()
          && pTarget->value.getID() != target.getID()
          && pTarget->next != NULL)
    {
      pTarget=pTarget->next;
    }
    if(pTarget->value.getID()==target.getID())
    {
      result=target;
      //head=pTarget->next;
      //delete head;
      //head=pTarget;
      return true;
    }
    else
    {
      return false;
    }
  }
  //template<class ItemType>

  bool deleteFirst()
  {
    if(head==NULL)
    {
      return false;
    }
    else
    {
      //Node<ItemType> *temp;
      //temp=head;
      //delete head; //not to leak a memory
      //temp=temp->next;
      head=head->next;
      //delete temp;
      //itemCount--;
      return true;
    }
  }
  bool Push(ItemType val)
  {
    Node<ItemType> *insNode=new Node<ItemType>; //pointer of type Node (it will be pointing to a node)

    //insNode=new Node;

    insNode->value=val;





    if(head==NULL)

    {

      head=insNode; //now insNode point is equal to head point

    }

    else

    {

      insNode->next=head; //taking this note an point it to the node head is pointing to

      insNode->value=val;

      head=insNode;

    }

    return true;

  }



  /* void addItem(ItemType a)
   {
   Node<ItemType> *newNode=new Node<ItemType>;
   newNode->value=a;
   Node<ItemType> *temp=head;
   if(head==NULL || newNode->value < this->head->value)//temp->value)
   {
   newNode->next=head;
   head=newNode;
   //itemCount++;
   }
   else
   {
   while(temp->next!=NULL && temp->next->value < newNode->value)
   {
   temp=temp->next;//this->head->next;//temp=temp->next;
   }
   newNode->next=temp->next;// set newNode->next to point to whatever is nemp->next is pointing to
   temp->next=newNode; //set temp->next to point to this node
   //itemCount++;
   }
   //free (temp);
   itemCount++;//////////////////////////
   // newNode->next=head;
   // head=newNode;
   }*/

  //IntStack IntStack::operator+(const IntStack &stack)const

  //{

  //   IntStack newStack;
  //}
  void addItem(Child *a)
  {
    //Child child(*a);

    Node<Child> *newNode=new Node<Child>;
    newNode->value=*a;//child;
    Node<ItemType> *temp=head;
    if(head==NULL || newNode->value.getLName() < temp->value.getLName())
    {
      newNode->next=head;
      head=newNode;
      //itemCount++;
    }
    else
    {
      while(temp->next!=NULL && temp->next->value.getLName() < newNode->value.getLName())
      {
        temp=temp->next;//this->head->next;//temp=temp->next;
      }
      newNode->next=temp->next;// set newNode->next to point to whatever is nemp->next is pointing to
      temp->next=newNode; //set temp->next to point to this node
      //itemCount++;
    }
    itemCount++;//////////////////////////
  }
  void addItem(Bird *bird)
  {
    //Child child(*a);
    Node<Bird> *newNode=new Node<Bird>;
    newNode->value=*bird;//child;
    Node<ItemType> *temp=head;
    if(head==NULL || newNode->value.getID() < this->head->value.getID())//temp->value)
    {
      newNode->next=head;
      head=newNode;
      //itemCount++;
    }
    else
    {
      while(temp->next!=NULL && temp->next->value.getID() < newNode->value.getID())

      {



        temp=temp->next;//this->head->next;//temp=temp->next;

      }

      newNode->next=temp->next;// set newNode->next to point to whatever is nemp->next is pointing to

      temp->next=newNode; //set temp->next to point to this node

      //itemCount++;

    }

    itemCount++;//////////////////////////

  }

  bool Merge(IntStack<Child> &list1, IntStack<Child> &list2)
  {
    Node<Child> *mergeNode=NULL;
    Node<Child> *lstNode;
    Node<Child> *list1Copy=list1.head;
    Node<Child> *list2Copy=list2.head;
    if(list1.head==NULL && list2.head==NULL)
    {
      return false;
    }
    else if(list1Copy==NULL)
    {
      mergeNode=list2Copy;
      //mergeNode->value=list2Copy->value;
      //mergeNode=mergeNode->next;
      //list2Copy=list2Copy->next;
      //Merge(list1, list2.head->next);
      //mergeNode->value=list2.head->value;
      //mergeNode
    }
    else if(list2Copy==NULL)
    {
      mergeNode=list1Copy;
      //mergeNode->value=list1Copy->value;
      //mergeNode=mergeNode->next;
      //list1Copy=list1Copy->next;
      //Merge(list1.head->next, list2);
    }
    while(list1Copy!=NULL && list2Copy!=NULL)
    {
      if(list1Copy->value.getLName() <= list2Copy->value.getLName())
      {
        mergeNode=list1Copy;

        //mergeNode->value=list1Copy->value;
        //mergeNode=mergeNode->next;
        list1Copy=list1Copy->next;
        //Merge(list1.head->next, list2);
      }
      else if(list1Copy->value.getLName() > list2Copy->value.getLName())
      {
        mergeNode=list2Copy;
        //delete list2Copy;
        list2Copy=list2Copy->next;
      }
    }
    //return true;

    if(list1Copy==NULL)
    {
      mergeNode->next=list2Copy;
    }
    else if(list2Copy==NULL)
    {
      mergeNode->next=list1Copy;
    }
    this->head=mergeNode;
    //cout<<mergeNode->value.getLName();
    ///////////??????????????????????????????
    return true;
  }
  //template <class T>
  friend ostream& operator<<(ostream & out, const IntStack<Child> & stack)
  {
    //Child child;
    Node<Child> *pNode=stack.head;
    while(pNode!=NULL)
    {
      out<<pNode->value.getLName()<<" "<<pNode->value.getFName()
      <<" "<<pNode->value.getAge()<<endl;
      pNode=pNode->next;
    }
    //out<<endl;
    return out;
  }
  //template <class T>

  /*friend ostream& operator<<(ostream & out, const IntStack & stack)
   {
   //Child child;
   Node<ItemType> *pNode=stack.head;
   while(pNode!=NULL)
   {
   out<<pNode->value<<" "; //<<endl;
   pNode=pNode->next;
   }
   out<<endl;
   return out;

   }*/

  //void IntStack:: operator=(IntStack &source)
  //{
  //}
  bool operator!=(const IntStack<ItemType> & list1)const
  {
     //return (this->value)
    Node<Child> *node1=this->head;
    Node<Child> *node2=list1.head;
    if(node1==NULL && node2==NULL)
    {
      return true; //true because they are both empty.
    }
    while(node1!=NULL && node2!=NULL)
    {
      if(node1->value.getLName()   == node2->value.getLName()
         && node1->value.getFName()== node2->value.getFName()
         && node1->value.getAge()  == node2->value.getAge())
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
    return true;
  }
  bool operator=(const IntStack<ItemType> &source)
  {
    //int x;
    while(this->head!=NULL)
    {
      //Pop(x);
      deleteFirst();
    }
    Node<ItemType> *newNodeP=source.head;
    while(newNodeP!=NULL)
    {
      addItem(&newNodeP->value);
      newNodeP=newNodeP->next;
    }
    return true;
    //head=newNodeP;
  }
  bool isEmpty()
  {
    return (this->head);
  }
  void clearList()
  {
    bool done=true;
    Node<ItemType> * current=head;
    while(current!=NULL && done!=false)
    {
      done=deleteFirst();
    }
    //head= current;
  }
  bool readFile(string FileName)
  {
    string line;
    ifstream file;
    //file.open(FileName);

    // while(getline(file, line))

    {

      //file>>ch.setLName()>>ch.setFName()>>ch.setAge();

    }
  }
  IntStack operator+(const IntStack <ItemType> node)const
  {

  }

  //IntStack operator=(const IntStack a);

  //void operator=(IntStack &);



  //friend ostream& operator<<(ostream & out, const IntStack &);



private:

  Node<ItemType> *head;

  int itemCount;

};



#endif /* defined(__LinkedL_332___IntStack__) */
