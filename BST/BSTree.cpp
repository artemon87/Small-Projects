#include "BSTree.h"
#include <iostream>
#include <queue>

using namespace std;

BSTree:: BSTree()
{

    //this->left=NULL;
    //this->riht=NULL;
    root=NULL;
}
BSTree:: ~BSTree()
{
  Empty();
}
/*bool BSTree:: Insert(Account *source)
{
  //Insert(source, root);
  //return true;
  Node *newNode=new Node;
  //Node *traversal;
  newNode->left=NULL;
  newNode->right=NULL;
  newNode->pAccnt=source;
  if(root==NULL)
  {
    root=newNode;
    return true;
  }
  else
  {
    Node *traversal=root;
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
          //break;
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
          //break;
        }
     }
      else
      {
        return false;
      }
    }
 }
  return true;
}*/
bool BSTree:: Insert(Account *source)
{
    Node *newNode=root;
    //newNode->pAccnt=source;
    //newNode->left=newNode->right=NULL;
    Insert(newNode, source);
    return true;
}
void BSTree:: Insert(Node *&node, Account *source)
{
  if(node==NULL)
  {
    node=new Node;
    node->pAccnt=source;
    node->left=node->right = NULL;
    return;
  }
  if(node->pAccnt > source)
  {
    Insert(node->left, source);
  }
  else
  {
    Insert(node->right, source);
  }
  
}
/*  
    Node *temp=root;
    Node *prev=NULL;
    while(temp != NULL)
    {
        cout<<*root->pAccnt<<endl;
        prev=temp;
        if(node->pAccnt < temp->pAccnt)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    if(prev==NULL)
    {
        node->left=root->left;
        node->right=root->right;
        root=node;
    }
    else
    {
        if(node->pAccnt < prev->pAccnt)
        {
            prev->left=node;
        }
        else
        {
            prev->right=node;
        }
    }
    cout<<*node->pAccnt<<endl;
    return true;*/

bool BSTree:: Retrive(const Account &target, Account *&found)const
{
    Node *search=root;

    //this->Display();
                     //cout<<"Target accnt "<<target.getAccount()<<endl;
                     //cout<<"Searching accnt"<<search->pAccnt->getAccount();
    if(search==NULL)
    {
        cout<<"TREE IS EMPTY"<<endl;
    }
    while(search!=NULL)
    {
        //cout<<*search->pAccnt<<endl;
        if(*search->pAccnt==target)
        {
            //cout<<"Searching accnt"<<SEarch->pAccnt->getAccount();
            //cout<<"Target accnt"<<target.getAccount();
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
void BSTree:: Display()const
{
  //Node *node=root;
  //Display(root->left, root);
  Display(root);
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
void BSTree:: Display(Node *node)const
{
  if(node != NULL)
  {
    if(node->left)
    {
      Display(node->left);
    }
    cout << *node->pAccnt;
    if(node->right)
    {
      Display(node->right);
    }
  }
}
void BSTree:: Empty()
{
  Empty(root);
}
void BSTree:: Empty(Node *node)
{

    /*if( node == NULL )
      return;
    if( node->left != NULL )
      Empty( node->left );
    if( node->right != NULL )
      Empty( node->right );

    delete node;

    return;*/
    if(node==NULL)
    {
        return;
    }
    if ( node->left != NULL )
    {
        Empty (node->left);
    }
    if(node->right != NULL)
    {
        Empty (node->right);
    }
      //node->pAccnt=NULL;
      delete node;
      return;
      //root=NULL;
}
bool BSTree:: isEmpty()
{
    return (this->root==NULL);
}
