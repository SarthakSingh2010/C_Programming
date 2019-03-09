#include<stdio.h>
#include<malloc.h>
struct node //FIFO
{
	int data;
	struct node *next;
};
void insert(struct node **front,struct node **rear, int val)  //enqueue: This operation adds a new node after rear and moves rear to the next node.
{															  //O(1)
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(*front==NULL)
	{
		*front=newnode;
		*rear=newnode;
	}
	else
	{
		(*rear)->next=newnode;
		*rear=newnode;
	}
}
int Delete(struct node **front) //dequeue: This operation removes the front node and moves front to the next node
{								// O(1)
	struct node *temp;
	int item;
	if(*front==NULL)
	{
		return -1;
	}
	else
	{
		temp=*front;
		item=temp->data;
		*front=(*front)->next;
		free(temp);
		return item;
	}
}
void delqueue(struct node **front)	//O(n)
{
	struct node *temp;
	if(*front==NULL)
	{
		printf("Deltion not possible\n");
	}
	else
	{
		while(*front!=NULL)
		{
			temp=*front;
			*front=(*front)->next;
			free(temp);
		}
	}
}
void display(struct node **front) //O(n)
{
	if(*front==NULL)
	{
		printf("Queue Empty\n");
	}
	else
	{
		struct node *temp;
		temp=*front;
		while(temp!=NULL)
		{
			printf("%d ---> ",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
int main()
{
	int choice,val;
	struct node *front=NULL;
	struct node *rear=NULL;
	do
	{
		printf("\n\nMenu:-\n01. Insert\n02. Delete\n03. Display\n04. Delete Queue\n05. Exit\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			printf("Enter data:\n");
			scanf("%d",&val);
			insert(&front,&rear,val);
		break;
		case 2:
			printf("%d deleted\n",Delete(&front));
		break;
		case 3:
			display(&front);
		break;
		case 4:
			delqueue(&front);
		break;
		}
	}while(choice!=5);
	return 0;
}
