//
//  IntStack.cpp
//  LinkedL(332)
//
//  Created by Artem Kovtunenko on 10/17/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include "IntStack.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*IntStack:: IntStack()
{
    head=NULL;
}
bool IntStack:: Pop(int &value)
{
    if(head==NULL)
    {
        return false;
    }
    else
    {
        Node *temp; //creating temp to copy the value from the first node 
        temp=head;
        head=head->next;
        value=temp->value;
        delete temp;
        return true;
    }
}
bool IntStack:: deleteFirst()
{
  if(head==NULL)
  {
    return false;
  }
  else
  {
    Node *temp=head->next;
    delete head;
    head=temp;
    return true;
  }
}
bool IntStack:: Push(int val)
{
    Node *insNode=new Node; //pointer of type Node (it will be pointing to a node)
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

void IntStack::addItem(int a)
{
    Node *newNode=new Node;
    newNode->value=a;
  /*Node *temp=head;
  
    if(head==NULL || newNode->value < temp->value)
        {
          newNode->next=head;
          head=newNode;
        }
    else
        {
          while(temp->next!=NULL && temp->next->value < newNode->value)
          {
            temp=temp->next;
          }
          newNode->next=temp->next;
          temp->next=newNode;
        }
  
  
  
    newNode->next=head;
    head=newNode;
}
//IntStack IntStack::operator+(const IntStack &stack)const
//{
 //   IntStack newStack;
    
//}

ostream& operator<<(ostream & out, const IntStack & stack)
{
    Node *pNode=stack.head;
    while(pNode!=NULL)
    {
        out<<pNode->value<<" ";
        pNode=pNode->next;
    }
    out<<endl;
    return out;
}

//void IntStack:: operator=(IntStack &source)
//{
    
//}
void IntStack::operator=(IntStack &source)
{
    //int x;
    while(this->head!=NULL)
    {
       //Pop(x);
        deleteFirst();
    }
    Node *newNodeP=source.head;
    while(newNodeP!=NULL)
    {
        addItem(newNodeP->value);
        newNodeP=newNodeP->next;
    }
    head=newNodeP;
}
    




    /*
void IntStack::operator=(IntStack &source)
{
    Node *sNode, *dNode, *insNode; //destination node
    dNode=this->head;
    
    int x;
    
    while(this->Pop(x))
    sNode=source.head;
    
    
    while(sNode!=NULL)
    {
        insNode=new Node;
        insNode->value=sNode->value;
        if(this->head==NULL)
        {
            this->head=insNode;
            dNode=this->head;
        }
    }
}
bool IntStack:: BuildList(string FileName)
{
  ifstream file;
  file.open(FileName);
  if(!file)
  {
    cout << "File could not be opened." << endl;
    return false;
  }
  else
  {
    Child object;
    object.
  }
}*/







