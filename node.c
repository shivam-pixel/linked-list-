#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;          // Data 
    struct node *next; // Address 
}*head;


void create(int n);
void insert(int data);
void insertEnd(int data);
void insertpos(int data,int position);
void display();


int main()
{
	int ch,n, f,data,position;
	printf("enter choice\n");
	printf("1 create\n");
	printf("2 insert\n");
	printf("3 insertend\n");
	printf("4 insertpos\n");
	printf("5 display\n");
	printf("6 exit\n");
	
	while(ch!=5)
	{
		printf("enter choice\n");
	printf("1 create\n");
	printf("2 insert\n");
	printf("3 insertend\n");
	printf("4 insertpos\n");
	printf("5 display\n");
	printf("6 exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);
    break;
    case 2:
    	printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);
     printf("\nData in the list \n");
    display();
    printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    insert(data);
     printf("\nData in the list \n");
    display();
    break;
   
    case 3:
    		printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);
    printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    insertEnd(data);
     printf("\nData in the list \n");
    display();
    break;
    case 4:
    	printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);
     printf("\nData in the list \n");
    display();
    	printf("nEnter data to insert at middle of the list: ");
    scanf("%d", &data);
    printf("Enter the position to insert new node: " );
    scanf("%d", &position);
    insertpos(data, position);
    	 printf("\nData in the list \n");
    display();
    	

     case 5:
    	 printf("\nData in the list \n");
    display();
    	
    case 6:
    	printf("end");
    	exit(0);
    	break;;
    	default:
    		printf("invalid");
    		break;
    	
    	
	}
}

    return 0;
}
void create(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; 
        head->next = NULL; 

        temp = head;
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

          
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; 
                newNode->next = NULL;
                temp->next = newNode; 
                temp = temp->next; 
            }
        }

        printf("SINGLY LINKED LIST CREATED\n");
    }
}
void insert(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = head; 

        head = newNode;         

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}
void insertEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; 
        newNode->next = NULL; 

        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
             temp->next = newNode; 
        printf("DATA INSERTED \n");
    }
}
void insertpos(int data, int position)
{
    int i;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link data part
        newNode->next = NULL;

        temp = head;
        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
              break;
        }

        if(temp != NULL)
        {
            /* Link address part of new node */
            newNode->next = temp->next; 

            /* Link address part of n-1 node */
            temp->next = newNode;

            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}
void display()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data);
            temp = temp->next;                
        }
    }
}
