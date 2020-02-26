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

void arrstor(int lis[], int &x, node* rt)
{
   if(rt!= nullptr)
   {
      arrstor(lis, x, rt->l);
      lis[x++] = rt -> item;
      arrstor(lis, x, rt->r);
   }
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


void bstsor(int y, int lis[])
{
   node* rt = nullptr;
   rt = insertRec(rt, lis[0]);
   for(int j = 1; j<y; j++)
   {
      insertRec(rt, lis[j]);
   }
   int j = 0;
   arrstor(lis, j, rt);
}

int main() 
{ 
    
    int lis[] = {6, 2, 8, 1, 9, 10}; 
    int y = sizeof(arr)/sizeof(arr[0]); 
    bstsor(y, lis); 
    for (int i=0; i<y; i++)
    { 
       cout << lis[i] << " "; 
    }
  
    return 0; 
} 