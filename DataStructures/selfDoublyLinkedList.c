#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
void createList(struct node **head,int val)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->prev=NULL;
	newnode->next=NULL;
	if(*head==NULL)
	*head=newnode;
	else
	{
		temp=*head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
	}
}
void displayList(struct node **head)
{
	struct node *temp;
	temp=*head;
	while(temp!=NULL)
	{
		printf("%d <----> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
void displayListReverse(struct node **head)
{
	struct node *temp;
	temp=*head;
	while(temp->next!=NULL)
	temp=temp->next;
	while(temp!=NULL)
	{
		printf("%d <----> ",temp->data);
		temp=temp->prev;
	}
	printf("NULL\n");
}
void insertbeg(struct node **head,int val)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->prev=NULL;
	newnode->next=NULL;
	if(*head==NULL)
	*head=newnode;
	else
	{
		newnode->next=*head;
		(*head)->prev=newnode;
		*head=newnode;
		
	}
}
int lengthOfList(struct node **head)
{
	struct node *temp;
	int c=0;
	temp=*head;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	return c;
}
void insertpos(struct node **head,int val,int pos)
{
	struct node *newnode,*temp,*temp1;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->prev=NULL;
	newnode->next=NULL;
	if(pos==1)
	insertbeg(&(*head),val);
	if(pos==lengthOfList(&(*head)))
	createList(&(*head),val);
	else
	{
		temp=*head;
		for(i=1;i<pos-1;i++)   //this does at pos  to do something like after position do this (i<pos)
		temp=temp->next;
		temp1=temp->next;
		newnode->next=temp1;
		temp1->prev=newnode;
		temp->next=newnode;
		newnode->prev=temp;
	}
}
void deletebeg(struct node **head)
{
	if(*head==NULL)
	printf("Deletion not possible\n");
	else
	{
		struct node *temp;
		temp=*head;
		*head=(*head)->next;
		(*head)->prev=NULL;
		free(temp);
	}
}
void deleteend(struct node **head)
{
	if(*head==NULL)
	{
		printf("Deletion not possible\n");
	}
	else
	{
		struct node *temp;
		temp=*head;
		while(temp->next!=NULL)
		temp=temp->next;
		temp->prev->next=NULL;
		free(temp);
	}
}
void deletepos(struct node **head,int pos)
{
	int i;
	struct node *temp;
	if(pos==1)
	deletebeg(&(*head));
	else
	if(pos==lengthOfList(&(*head)))
	deleteend(&(*head));
	else
	{
		temp=*head;
		for(i=1;i<pos;i++)
		{
			temp=temp->next;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}
}
main()
{
	int choice,val,pos;
	struct node *head=NULL;
	do
	{
		printf("\n\nMenu:-\n01. Create\n02. Display\n03. Display Reverse\n04. Insert Begin\n05. Insert position\n06. Length \n07. Delete at Begin\n08. Delete at End \n09. Delete at Position\n10. Exit\nEnter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data:\n");
				scanf("%d",&val);
				createList(&head,val);
				break;
			case 2:
				displayList(&head);
				break;
			case 3:
				displayListReverse(&head);
				break;
			case 4:
				printf("Enter data:\n");
				scanf("%d",&val);
				insertbeg(&head,val);
				break;
			case 5:
				printf("Enter position:\n");
				scanf("%d",&pos);
				printf("Enter data:\n");
				scanf("%d",&val);
				insertpos(&head,val,pos);
				break;
			case 6:
				printf("Lenght is : %d\n",lengthOfList(&head));
				break;
			case 7:
				deletebeg(&head);
				break;
			case 8:
				deleteend(&head);
				break;
			case 9:
				printf("Enter position:\n");
				scanf("%d",&pos);
				deletepos(&head,pos);
				break;
		}
	}while(choice!=10);
}
