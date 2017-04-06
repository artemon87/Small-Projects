//
//  BSTree.cpp
//  BinarySearchTree
//
//  Created by Artem Kovtunenko on 11/14/14.
//  Copyright (c) 2014 Artem Kovtunenko. All rights reserved.
//

#include "BSTree.h"
#include "Account.h"
#include <iostream>
#include <queue>

using namespace std;

BSTree:: BSTree()
{}
BSTree:: ~BSTree()
{
  Empty();
}
/*bool BSTree:: Insert(Account *source)
{
    Node *newNode;
    if(root==NULL)
    {
        newNode=new Node;
        newNode->pAccnt=source;
        newNode->left=NULL;
        newNode->right=NULL;
        root=newNode;
        return true;
    }
    while(true)
    {
        newNode=root;
        if(newNode->pAccnt > source)
        {
          if(newNode->left == NULL)
          {
            newNode=new Node;
            newNode->pAccnt=source;
            newNode->left=NULL;
            newNode->right=NULL;
            newNode->left=newNode;
            return true;
          }
          else
          {
            newNode=newNode->right;
          }
        }
        else if(newNode->pAccnt < source)
        {
          if(newNode->right == NULL)
          {
            newNode=new Node;
            newNode->pAccnt=source;
            newNode->left=NULL;
            newNode->right=NULL;
            newNode->right=newNode;
            return true;
          }
          else
          {
            newNode=newNode->right;
          }
        }
      return false;
    }
}*/
bool BSTree:: Insert(Account *source)
{
  //Insert(source, root);
  //return true;
  Node *newNode=new Node;
  Node *traversal;
  newNode->pAccnt=source;
  newNode->left=NULL;
  newNode->right=NULL;
  if(!root)
  {
    root=newNode;
    return true;
  }
  else
  {
    traversal=root;
    while(traversal != NULL)
    {
      if(traversal->pAccnt->getAccount() > source->getAccount())
      {
        if(traversal->left != NULL)
        {
          traversal=traversal->left;
        }
        else
        {
          traversal->left=newNode;
          break;
        }
      }
      else if(traversal->pAccnt->getAccount() < source->getAccount())
      {
        if(traversal->right != NULL)
        {
          traversal=traversal->right;
        }
        else
        {
          traversal->right=newNode;
          break;
        }
     }
      else
      {
        return false;
      }
    }
 }
  return true;
}
/*void BSTree:: Insert(Account *source, Node *&newNode)
{
  if(newNode==NULL)
  {
    newNode=new Node;
    newNode->pAccnt=source;
    newNode->left=NULL;
    newNode->right=NULL;
    //root=newNode;
  }
  else if(newNode->pAccnt > source)
  {
    Insert(source, newNode->left);
  }
  else
  {
    Insert(source, newNode->right);
  }
  
}*/
bool BSTree:: Retrive(const Account &target, Account *&found)const
{
    Node *search=root;
    
    while(search)
    {
        if(search->pAccnt->getAccount()==target.getAccount())
        {
            found=search->pAccnt;
            return true;
        }
        else if(search->pAccnt->getAccount() < target.getAccount())
        {
            search=search->right;
        }
        else if(search->pAccnt->getAccount() > target.getAccount())
        {
            search=search->left;
        }
    }
  return false;
}
/*void BSTree:: Display()//const throw (exception)
{
    Node *search=root;
    queue<Node *> qNode;
    bool done=false;
    if(this->root ==NULL)
    {
        cout<<"Tree is empty "<<endl;//throw exception('There is nothing to display');
    }
    while(!done || qNode.empty())
    {
        if(search!=NULL)
        {
            qNode.push(search);
            search=search->left;
        }
        else
        {
            search=qNode.front();
            Node *temp=qNode.front();
            cout<<qNode.front()<<" "<<endl;
            qNode.pop();
            //<<" "<<endl;
            search=search->right;
            
        }
    }

}*/
void BSTree:: Display()
{
  //Node *node=root;
  Display(root->left, root);
}
/*void BSTree:: Display(Node node){
  if(&node == NULL)
  {
    cout<<"Tree is empty"<<endl;
  }
  Display(*node.left);
  cout<<node.pAccnt<<" ";
  Display(*node.right);
}
*/
void BSTree:: Display(Node *traversNode, Node *parent)
{
  while (traversNode != NULL)
  {
    if (parent != NULL)
    {
      parent->left = traversNode->right;
      traversNode->right = parent;
    }
    
    if (traversNode->left != NULL)
    {
      parent = traversNode;
      traversNode = traversNode->left;
    }
    else
    {
      cout<<*traversNode->pAccnt;
      traversNode = traversNode->right;
      parent = NULL;
    }
  }
}
void BSTree:: Empty()
{
  Empty(root);
}
void BSTree:: Empty(Node *node)
{
  if(node != NULL)
  {
    Empty(node->right);
    Empty(node->left);
    delete node;
  }
}
bool BSTree:: isEmpty()
{
    return (this->root==NULL);
}



