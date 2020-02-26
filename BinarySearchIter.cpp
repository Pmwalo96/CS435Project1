#include <iostream>
using namespace std;

struct node
{
   node *l;
   node *r;
   int item;
};

node* anothernode(int value)
{
   node* n = new node;
   n->item = value;
   n->l = n->r = nullptr;
   return n;
}

void inord(node* rt)
{
   if(rt==nullptr)
   {
      return;
   }
   else
   {
      inord(rt->l);
      cout << rt->item << " ";
      inord(rt->r);
   }
}

node* insertIter(node* rt, int item)
{
   node* othernode = anothernode(item);
   node* a = rt;
   node* b = nullptr;
   while(a!=nullptr)
   {
      b=a;
      if(a->item > item)
      {
         a = a -> l;
      }
      else
      {
         a = a -> r;
      }
   }
   if(b == nullptr)
   {
      b=othernode;
   }
   else if(b->item < item)
   {
      b->r = othernode;
   }
   else
   {
      b->l = othernode;
   }
   return b;
}

node* findMinIter(node* rt)
{
   if(rt!=nullptr)
   {
      while(rt->l != nullptr)
      {
         rt = rt->l;
      }
      return rt;
   }
   else
   {
      return rt;
   }
}

node* findMaxIter(node* rt)
{
   if(rt!=nullptr)
   {
      while(rt->r != nullptr)
      {
         rt = rt->r;
      }
      return rt;
   }
   else
   {
      return rt;
   }
}

node* findPrevIter(node* rt, int value)
{
   node* prevnode = nullptr;
   while(1)
   {
      if(rt->item < value) //if root node is less than value, update prevnode to current node before going to right subtree
      {
         prevnode = rt;
         rt = rt->r;
      }
      else if(rt->item > value)
      {
         rt = rt->l;
      }
      else
      {
         if(rt->l)
         {
            prevnode = findMaxIter(rt->l);
         }
         break;
      }
      if(!rt)
      {
         return nullptr;
      }
     return prevnode;
   }
}

node* findNextIter(node* rt, node* m)
{
   node* afternode = nullptr;
   if(m->r != nullptr)
   {
      return findMinIter(m->r);
   }
   while(rt!=nullptr)
   {
      if(rt->item < m->item)
      {
         rt = rt->r;
      }
      else if(rt->item > m->item)
      {
         afternode = rt;
         rt = rt->l;
      }
      else
      {
         break;
      }
      return afternode;
}

void deleteRec(node* &rt, int value)
{
   if(rt==nullptr)
   {
      return;
   }
   if(rt->item < value)
   {
      deleteRec(rt->r, value);
   }
   else if(rt->item > value)
   {
      deleteRec(rt->l, value);
   }
   else
   {
      if(rt->r && rt->l)
      {
         node* pre = findmax(rt->l);
         rt->item = pre->item;
         deleteRec(rt->l,pre->item);
      }
      else if(rt->r == nullptr && rt->l == nullptr)
      {
         delete rt;
         rt = nullptr;
      }
      else
      {
         node* now = rt;
         node* ch = (rt->l)? rt->l: rt->r;
         rt = ch;
         delete now;
      }
   }
}

int main()
{
   node* rt = nullptr;
   int values[] = {2, 4, 6, 3, 10, 11};
   for(int value : values)
   {
      rt = insertIter(rt, value);
   }
   //deleteRec(rt, 6);
   inord(rt);
   cout << " " << findMaxIter(rt);
   cout << " " << findNextIter(rt, 9);
   return 0;
}
   