#include "BSTree.h"
#include "Transaction.h"
#include <iostream>
#include <queue>

using namespace std;

BSTree:: BSTree()
{

    //this->left=NULL;
    //this->riht=NULL;
   // root=NULL;
    //Node *newNode=NULL;
}
BSTree:: ~BSTree()
{
  //Empty();
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
bool BSTree:: Insert(Account *value)
{
  Node *current;
  Node *trailer;
  Node *newNode;

  // Create node to store value
  newNode = new Node;
  newNode->pAccnt = value;

  // Insert according to binary search tree criteria
  if( root == NULL )
    root = newNode;
  else
  {
    current = root;
    while( current != NULL )
      {
        trailer = current;
        if( current->pAccnt == value )
          {
            cout << "Duplicates not allowed" << endl;
            return false;
          }
        else
          if( current->pAccnt > value )
            current = current->left;
          else
            current = current->right;
      }
    if( trailer->pAccnt > value )
      trailer->left = newNode;
    else
      trailer->right = newNode;
  }
}
/*bool BSTree:: Insert(Account *source)
{
    Node *newNode=new Node;
    newNode->pAccnt=source;
    newNode->left=newNode->right=NULL;
    return(Insert(newNode));
}
bool BSTree:: Insert(Node *node)
{
    Node *temp=root;
    Node *prev=NULL;
    while(temp != NULL)
    {
        //cout<<*root->pAccnt<<endl;
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
    //cout<<*node->pAccnt<<endl;
    return true;
}*/
/*bool BSTree:: Insert(Account *source)
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
    root=node;
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
*/
bool BSTree:: Retrive(const Account &target, Account *&found)const
{
    Node *node=root;
    if(node==NULL)
    {
        return false;
    }
    while(node!=NULL)
    {
       if (node->pAccnt->getAccount()== target.getAccount())
       {
         found=node->pAccnt;
         return true;
       }
       else if(node->pAccnt->getAccount() > target.getAccount())
       {
         if(node->left != NULL)
         {
          node=node->left;
         }
         else{
            return false;
         }
       }
       else
       {
         cout<<node->pAccnt->getAccount();
         cout<<this->root->pAccnt->getAccount();
         if(node->right != NULL)
         {
          node=node->right;
         }
         else{
            return false;
         }
       }
    }
  return false;
}
//bool BSTree:: Retrive(const Account &target, Account *&found)const
//{
  //  return Retrive(target, found, root);
//}
    /*Node *search;
    search=this->root;
    if(search==NULL)
    {
        cout<<"TREE IS EMPTY"<<endl;
    }

    //this->Display();
                     //cout<<"Target accnt "<<target.getAccount()<<endl;
                     //cout<<"Searching accnt"<<search->pAccnt->getAccount();
    while(search!=NULL)
    {
        cout<<search->pAccnt<<endl;
        if(search->pAccnt->getAccount()==target.getAccount())
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
}*/
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
