#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	int priority;
	struct node *next;
};
void insert(struct node **front, struct node **rear, int val ,int prior){ //O(n)
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->priority=prior;
	newnode->next=NULL;
	if(*front==NULL){
		*front=newnode;
		*rear=newnode;
	}
	else if(prior <(*front)->priority){ // to change priority change < to >
			newnode->next=*front;
			*front=newnode;
		}
	else if(prior >=(*front)->priority){ // to change priority change >= to <=
		(*rear)->next=newnode;
		*rear=newnode;
	}
	else{
		temp=*front;
		while(temp->next->priority<=prior) // to change priority change <= to >=
			temp=temp->next;
		newnode->next=temp->next;
		temp->next=newnode;
	}
}
void Delete(struct node **front){ //O(1)
	struct node *temp;
	if(*front==NULL)
	printf("Empty\n");
	else{
		temp=*front;
		*front=(*front)->next;
		printf("Deleted item is %d\n",temp->data);
		free(temp);
	}
}
void display(struct node **front){ //O(n)
	struct node *temp;
	if(*front==NULL)
	printf("Empty\n");
	else{
		temp=*front;
		while(temp!=NULL){
			printf("(%d ,%d) --> ",temp->priority,temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
int main(){
	struct node *front=NULL;
	struct node *rear=NULL;
	int choice,val,prior;
	do{
		printf("\n\nMenu::\n01. Insert\n02. Delete\n03. Display\n04. Exit\nEnter your choice:-\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter priority\n");
				scanf("%d",&prior);
				printf("Enter value\n");
				scanf("%d",&val);
				insert(&front,&rear,val,prior);
			break;
			case 2:
				Delete(&front);
			break;
			case 3:
				display(&front);
			break;
		}
	}while(choice!=4);
	return 0;
}
