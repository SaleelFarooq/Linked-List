
#include<stdio.h>
#include<stdlib.h>

struct node{int data;
            struct node *left;
            struct node *right;
};
int ind;

/*struct node *insert(struct node *root,int p)
{
struct node *temp=(struct node *)malloc(sizeof (struct node));
temp->data=p;
temp->left=NULL;
temp->right=NULL;
if(root==NULL)
        {return temp;}
else
        {struct node *ptr=(struct node *)malloc(sizeof (struct node));
         //while(ptr!=NULL)
                //{
                    if(p<ptr->data)
                        {ptr->left=insert(ptr->left,p);}
                    else if(p>ptr->data)
                        {ptr->right=insert(ptr->right,p);}
               // }
        }
}
*/
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}


struct node* insert(struct node* node, int key)
{

    if (node == NULL) return newNode(key);


    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);


    return node;
}




int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);


        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}


void printInorder(struct node* node)
{
     if (node == NULL)
          return;


     printInorder(node->left);

     /* then print the data of node */
     printf("%d ", node->data);

     /* now recur on right child */
     printInorder(node->right);
}

void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void displayLevelorder(struct node* root)
{
    int h = height(root);
    //printf("Height of tree = %d\n",h);
    int i;
    for (i=1; i<=h; i++)
        {printGivenLevel(root, i);
        printf("\n");
        }
}



void storetoarray(struct node* ptr,int arr1[])
{
     if (ptr == NULL)
          return;


     storetoarray(ptr->left,arr1);

    arr1[ind]=ptr->data;
    ind++;

     /* now recur on right child */
     storetoarray(ptr->right,arr1);
}


struct node* buildbaltree(int arr1[], int start, int end)
{

    if (start > end)
      return NULL;


    int mid = (start + end)/2;
    struct node *root = newNode(arr1[mid]);


    root->left =  buildbaltree(arr1, start, mid-1);


    root->right = buildbaltree(arr1, mid+1, end);

    return root;
}







void main()
{
    int n,i,temp;
//printf("Enter no.of elements\t");
scanf("%d",&n);
//printf("%d",n);
struct node *root=(struct node *)malloc(sizeof (struct node));
root=NULL;
for(i=0;i<n;i++)
        {scanf("%d",&temp);
        //printf("%d",temp);
        root=insert(root,temp);
        }
displayLevelorder(root);
//printInorder(root);
int arr1[n];
ind=0;
storetoarray(root,arr1);
struct node *root1=(struct node *)malloc(sizeof (struct node));
root1=buildbaltree(arr1,0,ind-1);
displayLevelorder(root1);
}
