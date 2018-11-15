#include<iostream>
using namespace std;
struct node
{
 int data;
 struct node *next;
 struct node *prev;
};
class vishal
{
 public:
 struct node *start=NULL;
 void ins(int a)
 {
  struct node *t=new node;
  t->data=a;
  t->next=NULL;
  t->prev=NULL;
  if(start==NULL)
  {
   start=t;
  }
  else
  {
    node *p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=t;
    t->prev=p;
  }
 }
 void dis()
 {
     node *p=start;
     while(p->next!=NULL)
     {
         p=p->next;
     }
     p->next=start;
     p=start;
     while(p->next!=start)//display
     {
         cout<<p->data<<endl;
         p=p->next;
     }
     cout<<p->data;
 }
};
int main()
{
 vishal v;
 int n,a;
 cout<<"enter size ";
 cin>>n;
 for(int i=0;i<n;i++)
 {
     cin>>a;
     v.ins(a);
 }
 v.dis();
}
