#include <iostream>
#include <vector>

using namespace std;

 vector<int> v1;



struct node{
            int data;
            struct node *left;
            struct node *right;
};





struct node* inserttobst(struct node *root,int key)
{struct node *temp=(struct node*)malloc(sizeof (struct node));
temp->data=key;
temp->left=NULL;
temp->right=NULL;

if(root==NULL)
        {return temp;}
if(key<root->data)
        {root->left=inserttobst(root->left,key);}
else if(key>root->data)
        {root->right=inserttobst(root->right,key);}
return root;
}



void inorder(struct node *root)
{if(root==NULL)
        return ;
 inorder(root->left);
 cout<<root->data<<" ";
 inorder(root->right);
}




int height(struct node *root)
{if(root==NULL)
        return 0;
int h1,h2;
h1=height(root->left);
h2=height(root->right);
if(h1>h2)
        return (h1+1);
else
        return (h2+1);
}



void printgivenlevel(struct node *root,int level)
{
if(root==NULL)
        return ;
if(level==1)
        cout<<root->data<<" ";
else
        {printgivenlevel(root->left,level-1);
        printgivenlevel(root->right,level-1);
        }
}



void levelorder(struct node *root,int ht)
{if(root==NULL)
        return ;
int i;
for(i=1;i<=ht;i++)
        {printgivenlevel(root,i);
        cout<<"\n";
        }
}


void storetovector(struct node *root)
{if(root==NULL)
        return ;
storetovector(root->left);
v1.push_back(root->data);
storetovector(root->right);
}


struct node *buildbalancedtree(vector<int> v1,int start,int end)
{if(start>end)
        return NULL;
int mid=(start+end)/2;
struct node *root=(struct node *)malloc(sizeof (struct node));
root->data=v1[mid];
root->left=buildbalancedtree(v1,start,mid-1);
root->right=buildbalancedtree(v1,mid+1,end);
return root;
}




int main()
{int n,i,temp;
    struct node *root=(struct node *)malloc(sizeof (struct node));
    root=NULL;
  cin>>n;
  for(i=0;i<n;i++)
        {cin>>temp;
         root=inserttobst(root,temp);
        }
 cout<<"Tree is constructed,not balanced.."<<"\n";
 inorder(root);
 cout<<"\n";
 int ht=height(root);
 cout<<"Height of BST constructed is "<<ht<<"\n";
 cout<<"Level Order Traversal of the BST is .."<<"\n";
 levelorder(root,ht);

 storetovector(root);
 cout<<"Length of vector is "<<v1.size()<<"\n";
 struct node *root1=(struct node *)malloc(sizeof (struct node));
 root1=buildbalancedtree(v1,0,(v1.size()-1));
 ht=height(root1);
 cout<<"The balanced BST is .."<<"\n";
 levelorder(root1,ht);
}
