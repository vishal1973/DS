#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *root=NULL;
class visk
{
 public:
     int s=0;
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
 int searchs(int a,node * temp)
 {
     if(temp!=NULL)
     {
          if(a==temp->data)
        {
            s=1;
        }
         searchs(a,temp->left);
        searchs(a,temp->right);
     }
     else if(temp==NULL)
     {
         return s;
     }
 }
 void maxs(node *temp)
 {
     while(temp->right!=NULL)
     {
         temp=temp->right;
     }
     cout<<"max="<<temp->data;
 }
 void mins(node *temp)
 {
     while(temp->left!=NULL)
     {
         temp=temp->left;
     }
    cout<<"min="<<temp->data;
 }
 int minhei(node *temp)
 {
     if(temp==NULL)
       {
           return 0;
       }
     else
     {
         int l=minhei(temp->left);
         int r=minhei(temp->right);
         if(l<r)
            return (l+1);
         else
            return (r+1);
     }
 }
 int maxhei(node *temp)
 {
     if(temp==NULL)
        return 0;
     else
     {
     int l=maxhei(temp->left);
     int r=maxhei(temp->right);
     if(l>r)
        return (l+1);
     else
        return (r+1);
     }
 }
 void inorder(node *temp)
 {
     if(temp!=NULL)
     {
        inorder(temp->left);
         cout<<temp->data<<" ";
         inorder(temp->right);
     }
 }
 void preorder(node *temp)
 {
     if(temp!=NULL)
     {
         cout<<temp->data<<" ";
         preorder(temp->left);
         preorder(temp->right);
     }
 }
 void postorder(node *temp)
 {
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<" ";
    }
 }
};
int main()
{
 visk v;
 int a,n,s,r;
 cout<<"enter ";
 cin>>n;
 cout<<endl;
 for(int i=0;i<n;i++)
 {
     cin>>a;
     v.ins(a,root);  //if root is made in class then use ->v.root
 }
 cout<<"enter ele to be searched ";
 cin>>s;
 r=v.searchs(s,root);
 if(r==1)
 cout<<"\nfound\n";
 else
    cout<<"\nnot\n";

 v.maxs(root);//maximum & minimum
 cout<<endl;
 v.mins(root);

 cout<<"\n min height or min depth of tree (maybe wrong)";
 int h=v.minhei(root);
 cout<<h;

 cout<<"\n max height or max depth of tree ";
 h=v.maxhei(root);
 cout<<h;

 cout<<"\nin\n";
 v.inorder(root);
 cout<<"\npre\n";
 v.preorder(root);
 cout<<"\npost\n";
 v.postorder(root);
}
