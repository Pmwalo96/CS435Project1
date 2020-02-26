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

node* minsearch(node* rt)
{
   while(rt->l != nullptr)
   {
      rt = rt->l;
   }
   return rt;
}

node* insertRec(node* rt, int value)
{
   if(nullptr == rt)
   {
      return anothernode(value);
   }
   
   if(value > rt->item)
   {
      rt -> r = insertRec(rt->r, value);
   }
   
   else
   {
      rt-> l = insertRec(rt->l, value);
   }
   return rt;
}

int findMinRec(node* rt)
{
   if(rt->l != nullptr)
   {
      return findMinRec(rt->l);
   }
   
   else
   {
      return rt -> item;
   }
}

int findMaxRec(node* rt)
{
   if(rt->r != nullptr)
   {
      return findMaxRec(rt->r);
   }
   
   else
   {
      return rt -> item;
   }
}

int findPrevRec(node* rt, int value)
{
   if(rt == nullptr)
   {
      return -1;
   }
   else if(rt -> item <= value)
   {
      int x = findPrevRec(rt->r, value);
      if(x != -1)
      {
         return x;
      }
      else
      {
         return rt->item;
      }
   }
   else if(rt -> item > value)
   {
      return findPrevRec(rt->l, value);
   }
}

int findNextRec(node* rt, int value)
{
   if ((rt->l == nullptr) && (rt->r == nullptr) && (rt->item < value))
   {
      return -1;
   }
   
   if((value > rt->l->item && value <= rt->item) || (value <= rt->item && rt->l == nullptr))
   {
      return rt->item;
   }
   
   if(value <= rt->item)
   {
      return findNextRec(rt->l, value);
   }
   
   else
   {
      return findNextRec(rt->r, value);
   }
}

node* findmax(node* pt)
{
   while(pt->r != nullptr)
   {
      pt=pt->r;
   }
   return pt;
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
      rt = insertRec(rt, value);
   }
   //deleteRec(rt, 6);
   inord(rt);
   cout << " " << findMaxRec(rt);
   cout << " " << findNextRec(rt, 9);
   return 0;
}