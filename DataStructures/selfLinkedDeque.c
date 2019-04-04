#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
void insertFront(struct node **front,struct node **rear,int val){ //O(1)
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(*front==NULL){
		*front=newnode;
		*rear=newnode;
	}
	else{
		newnode->next=*front;
		*front=newnode;
	}
}
void insertRear(struct node **front,struct node **rear,int val){ //O(1)
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(*front==NULL){
		*front=newnode;
		*rear=newnode;
	}
	else{
		(*rear)->next=newnode;
		*rear=newnode;
	}
}
int deleteFront(struct node **front,struct node **rear){ //O(1)
	struct node *temp;
	int item;
	if(*front==NULL)
	return -1;
	if(*front==*rear){
		item=(*front)->data;
		free(*front);
		*front=NULL;
		return item;
	}
	else{
		temp=*front;
		*front=(*front)->next;
		item=temp->data;
		free(temp);
		return item;
	}
}
int deleteRear(struct node **front,struct node **rear){ //O(n)
	struct node *temp,*save;
	int item;
	if(*front==NULL)
	return -1;
	if(*front==*rear){
		item=(*rear)->data;
		free(*rear);
		*rear=NULL;
		*front=NULL;
		return item;
	}
	else{
		temp=*front;
		while(temp->next!=NULL){
			save=temp;
			temp=temp->next;
		}
		item=temp->data;
		save->next=NULL;
		free(temp);
		*rear=save;
		return item;
	}
}
void display(struct node **front){ //O(n)
	if(*front==NULL)
	printf("Empty\n");
	else{
		struct node *temp;
		temp=*front;
		while(temp!=NULL){
			printf("%d --> ",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
int main()
{
	struct node *front=NULL;
	struct node *rear=NULL;
	int choice,val;
	do
	{
		printf("\n\nMenu:-\n01. Insert Front\n02. Insert Rear\n03. Delete Front\n04. Delete Rear\n05. Display\n06. Exit\nEnter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data\n");
				scanf("%d",&val);
				insertFront(&front,&rear,val);
			break;
			case 2:
				printf("Enter data\n");
				scanf("%d",&val);
				insertRear(&front,&rear,val);
			break;
			case 3:
				printf("Item %d deleted\n",deleteFront(&front,&rear));
			break;
			case 4:
				printf("Item %d deleted\n",deleteRear(&front,&rear));
			break;
			case 5:
				display(&front);
			break;
		}
	}while(choice!=6);
	return 0;
}
