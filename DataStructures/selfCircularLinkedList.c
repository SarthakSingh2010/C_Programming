#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void insertAtEnd(struct node **head,int val){ //O(n)
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(*head==NULL){
		*head=newnode;
		newnode->next=newnode;
		return;
	}
	temp=*head;
	while(temp->next!=*head)
		temp=temp->next;
	temp->next=newnode;
	newnode->next=*head;
}
void insertAtBegin(struct node **head,int val){ //O(n)
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	if(*head==NULL){
		*head=newnode;
		newnode->next=newnode;
		return;	
	}
	temp=*head;
	while(temp->next!=*head)
		temp=temp->next;
	temp->next=newnode;
	newnode->next=*head;
	*head=newnode;
}
int deleteAtBegin(struct node **head){ //O(n)
	struct node *temp;
	if(*head==NULL)
		return -1;
	if((*head)->next==head){
		int val=(*head)->data;
		free(*head);
		*head=NULL;
		return val;
	}
	temp=*head;
	while(temp->next!=*head)
		temp=temp->next;
	temp->next=(*head)->next;
	int val=(*head)->data;
	free(*head);
	*head=temp->next;
	return val;
}
int deleteAtEnd(struct node **head){ //O(n)
	struct node *temp,*save;
	if(*head==NULL)
		return -1;
	if((*head)->next==head){
		int val=(*head)->data;
		free(*head);
		*head=NULL;
		return val;
	}
	temp=*head;
	while(temp->next!=*head){
		save=temp;
		temp=temp->next;
	}
	save->next=*head;
	int val=temp->data;
	free(temp);
	return val;
}
void display(struct node **head){ //O(n)
	struct node *temp=*head;
	if (*head==NULL)
		return;
	while(temp->next!=*head){
		printf("%d --> ",temp->data);
		temp=temp->next;
	}
	printf("%d --> %d\n",temp->data,temp->next->data);
}
int isEmpty(struct node **head){ //O(1)
	if(*head==NULL)
		return 1;
	return 0;		
}
int length(struct node **head){ //O(n)
	struct node *temp;
	int len=1;
	if(*head==NULL)
		return 0;
	temp=*head;
	while(temp->next!=*head){
		len++;
		temp=temp->next;
	}
	return len;
}
void insertAtPos(struct node **head,int pos,int val){ //O(p)
	struct node *newnode,*temp,*temp1;
	int i,len=length(&(*head));
	if(pos>len || pos<1)
		return;
	if(pos==1){
		insertAtBegin(&(*head),val);
		return;
	}
	if(pos==len){
		insertAtEnd(&(*head),val);
		return;	
	}
	temp=*head;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	for(i=1;i<pos-1;i++)
		temp=temp->next;
	temp1=temp->next;
	newnode->next=temp1;
	temp->next=newnode;
}
int deleteAtPos(struct node **head,int pos){ //O(p)
	int i,len=length(&(*head));
	struct node *temp,*save;
	if(pos>len || pos<1)
		return -1;
	if(pos==1)
		return deleteAtBegin(&(*head));
	if(pos==len)
		return deleteAtEnd(&(*head));
	temp=*head;
	for(i=1;i<pos;i++){
		save=temp;
		temp=temp->next;
	}
	save->next=temp->next;
	int val=temp->data;
	free(temp);
	return val;
}
int main()
{
	int choice,val,pos;
	struct node *head=NULL;
	do
	{
		printf("\n\nMenu:-\n01. Insert End\n02. Display\n03. Insert Begin\n04. Insert position\n05. Length \n06. Delete at Begin\n07. Delete at End \n08. Delete at Position\n09. Exit\nEnter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data:\n");
				scanf("%d",&val);
				insertAtEnd(&head,val);
				break;
			case 2:
				display(&head);
				break;
			case 3:
				printf("Enter data:\n");
				scanf("%d",&val);
				insertAtBegin(&head,val);
				break;
			case 4:
				printf("Enter position:\n");
				scanf("%d",&pos);
				printf("Enter data:\n");
				scanf("%d",&val);
				insertAtPos(&head,pos,val);
				break;
			case 5:
				printf("Lenght is : %d\n",length(&head));
				break;
			case 6:
				printf("%d deleted\n",deleteAtBegin(&head));
				break;
			case 7:
				printf("%d deleted\n",deleteAtEnd(&head));
				break;
			case 8:
				printf("Enter position:\n");
				scanf("%d",&pos);
				printf("%d deleted from %d position\n",deleteAtPos(&head,pos),pos);
				break;
		}
	}while(choice!=9);
	return 0;
}
