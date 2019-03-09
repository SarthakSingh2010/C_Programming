#include<stdio.h>
#include<malloc.h>
struct node  //LIFO
{
	int data;
	struct node *next;
};
void push(struct node **top,int item) //O(1)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->next=NULL;
	if(*top==NULL)
	*top=newnode;
	else
	{
		newnode->next=*top;
		*top=newnode;
	}
}
int pop(struct node **top) //O(1)
{
	struct node *temp;
	int item;
	if(*top==NULL)
	return -1;
	else
	{
		temp=*top;
		item=temp->data;
		*top=(*top)->next;
		free(temp);
		return item;
	}
}
int peek(struct node **top) //O(1)
{
	if(*top==NULL)
	return -1;
	else
	{
		return (*top)->data;
	}
}
void delstack(struct node **top) //O(n)
{
	struct node *temp;
	if(*top==NULL)
	printf("stack empty\n");
	else
	{
		while(*top!=NULL)
		{
			temp=*top;
			*top=(*top)->next;
			free(temp);
		}
	}
}
void display(struct node **top) //O(n)
{
	if(*top==NULL)
	printf("Stack empty\n");
	else
	{
		struct node *temp;
		temp=*top;
		printf("[TOP]\n");
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
	struct node *top=NULL;
	do
	{
		printf("\n\nMenu:-\n01. Push\n02. Pop\n03. Peek\n04. Delete Stack\n05. Display\n06. Exit\nEnter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data\n");
				scanf("%d",&val);
				push(&top,val);
			break;
			case 2:
				printf("Item %d deleted\n",pop(&top));
			break;
			case 3:
				printf("Item at top is %d\n",peek(&top));
			break;
			case 4:
				delstack(&top);
			break;
			case 5:
				display(&top);
			break;
		}
	}while(choice!=6);
	return 0;
}
