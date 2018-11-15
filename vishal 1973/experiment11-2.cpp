#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
class visk
{
 public:
 node *root=NULL;
 void ins(int a,node *temp)
 {
     struct node *t=new node;
     t->data=a;
     t->left=NULL;
     t->right=NULL;
     if(root==NULL)
     {
         root=t;
     }
     else if(a<temp->data)
     {
         if(temp->left==NULL)
         {
             temp->left=t;
         }
         else
         {
             ins(a,temp->left);
         }
     }
     else
     {
         if(temp->right==NULL)
         {
             temp->right=t;
         }
         else
         {
             ins(a,temp->right);
         }
     }
 }
 node* findMin(node *root)
 {
     node *temp=root;
     while(temp->left!=NULL)
     {
         temp=temp->left;
     }
     return temp;
 }
 node* del(int a,node *root)
 {
     if(root==NULL)
     {
         return NULL;
     }
     else if(a<root->data)
     {
         root->left=del(a,root->left);
     }
     else if(a>root->data)
     {
         root->right=del(a,root->right);
     }
     else
     {
       if(root->left==NULL && root->right==NULL)
       {
           delete(root);
           root=NULL;
       }
       else if(root->left==NULL)
       {
           node *temp=root;
           root=root->right;
           delete(temp);
       }
       else if(root->right==NULL)
       {
           node *temp=root;
           root=root->left;
           delete(temp);
       }
       else
       {
           node *temp=findMin(root->right);
           root->data=temp->data;
           root->right=del(temp->data,root->right);
       }
     }
     return root;
 }
 void disp(node *temp)
 {

     if(temp!=NULL)
     {
         disp(temp->left);
         cout<<temp->data<<" ";
         disp(temp->right);
     }
 }
};
int main()
{
    int n,a;
    visk v;
    cout<<"enter ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.ins(a,v.root);
    }
    cout<<"\nenter ele to be del ";
    cin>>a;
    v.del(a,v.root);
    v.disp(v.root);
}
