    TR:: TR()
    {
      root=NULL;
    }
    TR:: ~TR()
    {}
    bool TR:: add(Obj *obj)
    {
      Node *temp=root;
      Node *newNode=new Node;
      newNode->left=newNode->right=NULL;
      newNode->object=obj;
      if(root==NULL)
      {
        root=newNode;
        return true;
      }
      while(temp!=NULL)
      {
        if(temp->object > obj)
        {
          temp=
      
    bool display();
    bool display(Node *node);