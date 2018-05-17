#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

struct node *insert(struct node *head,int temp)
{struct node *tnode=(struct node *)malloc(sizeof (struct node));
tnode->data=temp;
tnode->next=NULL;
//printf("%d",temp);
if(head==NULL)
        head=tnode;
else
        {struct node *ptr=(struct node *)malloc(sizeof (struct node));
        ptr=head;
        while(ptr->next!=NULL)
                    {ptr=ptr->next;}
        ptr->next=tnode;
        }
//printf("%d",temp);
return head;
}







void printit(struct node *head)
{while(head!=NULL)
        {printf("%d -->",head->data);
        head=head->next;
        }
}


/*void Reverse(struct node* head)
{
    struct node* first;
    struct node* rest;


    if (head== NULL)
       return;


    first = head;
    rest  = first->next;


    if (rest == NULL)
       return;


    Reverse(rest);
    first->next->next  = first;


    first->next  = NULL;


    head = rest;
}
*/

struct node *recursiveReverseLL(struct node *list)
{
    struct node *revHead;
    if (list == NULL || list->next == NULL)
    {
        return list;
    }
    /*
    revHead = recursiveReverseLL(list->next);
    list->next->next = list;
    list->next = NULL;
    */
    struct node *first=(struct node *)malloc(sizeof (struct node));
    first->data=list->data;
    first->next=NULL;

    struct node *rest=(struct node *)malloc(sizeof (struct node));
    rest=list->next;
    revHead=recursiveReverseLL(rest);
    struct node *ptr=(struct node *)malloc(sizeof (struct node));
    ptr=revHead;
    while(ptr->next!=NULL)
            {ptr=ptr->next;}
    ptr->next=first;
    return revHead;
}

/*struct node *sortLL(struct node *list)
{if(list==NULL || list->next==NULL)
        {return list;}
}
*/
void main()
{
    int n,i,temp;
//printf("Enter no.of elements\t");
scanf("%d",&n);
//printf("%d",n);
struct node *head=(struct node *)malloc(sizeof (struct node));
head=NULL;
for(i=0;i<n;i++)
        {scanf("%d",&temp);
        //printf("%d",temp);
        head=insert(head,temp);
        }
printf("Linked list is ..\t");
if(head==NULL)
        printf("Not inserted\n");
printit(head);
printf("\n");
head=recursiveReverseLL(head);
//head=sortLL(head);
printf("Linked list is ..\t");
if(head==NULL)
        printf("Not inserted\n");
printit(head);
}
