// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};
struct node *newnode,*head=NULL,*current=NULL,*prev=NULL;

void create(int n)
{
	int i=1;
	printf("Enter Data: ");
	while (i<=n)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if (head==NULL)
			head=current=newnode;
		else
		{
			current->next=newnode;
			current =current->next;
		}
		i++;
	}
}

void display()
{
	current=head;
	while (current!=NULL)
	{
		printf("%d\t",current->data);
		current=current->next;
	}
}


void insertStart()
{
	int item;
	printf("Enter Data: ");
	scanf("%d",&item);
	newnode=(struct node*)malloc(sizeof(struct node));
	if (newnode==NULL)
		printf("Insufficient memory ");
	else 
	{
		newnode->data=item;
		newnode->next=head;
		head=newnode;
	}
}

void insertEnd()
{
	int item;
	printf("Enter Data: ");
	scanf("%d",&item);
	newnode=(struct node*)malloc(sizeof(struct node));
	if (newnode==NULL)
		printf("Insufficient memory ");
	else 
	{
		newnode->data=item;
		newnode->next=NULL;
		current=head;
		while (current->next!=NULL)
		{
			current=current->next;	
		}
		current->next=newnode;
	}
}

void insertLoc()
{
	int item,pos;
	printf("Enter position: ");
	scanf("%d",&pos);
	printf("Enter Data: ");
	scanf("%d",&item);
	newnode=(struct node*)malloc(sizeof(struct node));
	if (newnode==NULL)
		printf("Insufficient memory ");
	else 
	{
		current=head;
		int count=0;
		while(current!=NULL)
		{
			current=current->next;
			count++;
		}
		if ((pos>count)||(pos<1))
			printf("Invalid Position...");
		else
		{
			newnode->data=item;
			current=head;
			for (int i=1;i<pos-1;i++)
			{
				current=current->next;
			}
			newnode->next=current->next;
			current->next=newnode;
		}
	}
}

void delFront()
{
	if (head==NULL)
		printf("List Empty...");
	else if (head->next==NULL)
	{
		current=head;
		head=NULL;
		free(current);
	}
	else 
	{
		current=head;
		head=head->next;
		free(current);
	}
}

void delEnd()
{
	if (head==NULL)
		printf("List Empty...");
	else if (head->next==NULL)
	{
		current=head;
		head=NULL;
		free(current);
	}
	else 
	{
		current=head;
		while (current->next!=NULL)
		{
			prev=current;
			current=current->next;
		}
		prev->next=NULL;
		free(current);
	}
}

void delLoc()
{
	int pos;
	printf("Enter position: ");
	scanf("%d",&pos);
	int count=0;
	current=head;
	while(current!=NULL)
	{
		current=current->next;
		count++;
	}
	if (head==NULL)
		printf("List Empty...");
	else if ((pos>count)||(pos<1))
		printf("Invalid Position...");
	else if (pos == 1) 
	{
		current = head;
		head = head->next;
		free(current);
	}
	else 
	{
		current=head;
		for (int i=1;i<=pos-1;i++)
		{
			prev=current;
			current=current->next;
		}
		prev->next=current->next;
		free(current);
	}
}


void main()
{
	int n,opt;
	char ch;
	printf("Enter number of Nodes: ");
	scanf("%d",&n);
	create(n);
	printf("\n1.Insert at Front\n2.Insert at End\n3.Insert at Location\n4.Delete at Front\n5.Delete at End\n6.Delete at Location\n7.Display\n");
	do
	{
		printf("Enter option\n");
		scanf("%d",&opt);
		switch (opt)
		{
			case 1:
				insertStart();
				break;
			case 2:
				insertEnd();
				break;
			case 3:
				insertLoc();
				break;
			case 4:
				delFront();
				break;
			case 5:
				delEnd();
				break;
			case 6:
				delLoc();
				break;
			case 7:
				display();
				break;
			default	:
				printf("Invalid Option");
				break;
		}
		printf("\nDo you want to continue: ");
		scanf(" %c",&ch);
	}
	while((ch=='y')||(ch=='Y'));
}