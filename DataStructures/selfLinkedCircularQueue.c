#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};
void insert(struct node **front,struct node **rear,int val){ //O(1)
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(*front==NULL){
		*front=newnode;
		*rear=newnode;
	}
	else{
		(*rear)->next=newnode;
		*rear=newnode;
		(*rear)->next=*front;
	}
}
int Delete(struct node **front,struct node **rear){ //O(1)
	struct node *temp;
	int item;
	if(*front==NULL)
	return -1;
	else if(*front==*rear){
		item=(*front)->data;
		*front=NULL;
		*rear=NULL;
		return item;
	}
	else{
		temp=*front;
		item=temp->data;
		(*rear)->next=temp->next;
		*front=(*front)->next;
		free(temp);
		return item;
	}
}
void display(struct node **front){ //O(n)
	struct node *temp;
	if(*front==NULL)
		printf("Empty\n");
	else{
		temp=*front;
		while(temp->next!=*front){
			printf("%d --> ",temp->data);
			temp=temp->next;
		}
		printf("%d --> %d\n",temp->data,temp->next->data);
	}
}
int main(){
	struct node *front=NULL;
	struct node *rear=NULL;
	int choice,val;
	do
	{
		printf("\n\nMenu:-\n01. Insert\n02. Delete\n03. Display\n04. Exit\nEnter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data\n");
				scanf("%d",&val);
				insert(&front,&rear,val);
			break;
			case 2:
				printf("Item %d deleted\n",Delete(&front,&rear));
			break;
			case 3:
				display(&front);
			break;
		}
	}while(choice!=4);
	return 0;
}
