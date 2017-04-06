#ifndef _TR_H_
#define _TR_H_

using namespace std;

struct Node
{
  Node *left;
  Node *right;
  Obj *object;
}
class TR
{
  private:
    Node *root;
  public:
    TR();
    ~TR();
    bool add(Obj *obj);
    bool display();
    bool display(Node *node);
{;

#endif