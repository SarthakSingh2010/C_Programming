#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void insertAtEnd(struct node **head,int val){  //O(n)
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=NULL;
	newnode->data=val;
	if(*head==NULL)
		*head=newnode;
	else{
		temp=*head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newnode;
	}
}
void insertAtBegin(struct node **head,int val){ //O(1)
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->next=NULL;
	newnode->data=val;
	if(*head==NULL)
		*head=newnode;
	else{
		newnode->next=*head;
		*head=newnode;
	}
}
int deleteAtBegin(struct node **head){ //O(1)
	struct node *temp;
	temp=*head;
	if(*head==NULL)
		return -1;
	int val=(*head)->data;
	*head=(*head)->next;
	free(temp);
	return val;
}
int deleteAtEnd(struct node **head){ //O(n)
	struct node *temp,*save;
	if(*head==NULL)
		return -1;
	if((*head)->next==NULL){
		int val=(*head)->data;
		free(*head);
		*head=NULL;
		return val;
	}
	temp=*head;
	while(temp->next!=NULL){
		save=temp;
		temp=temp->next;
	}
	int val=temp->data;
	save->next=NULL;
	free(temp);
	return val;
}
void print(struct node **head){ //O(n)
	struct node *temp;
	for(temp=*head;temp!=NULL;temp=temp->next)
		printf("%d --> ",temp->data);
	printf("NULL\n");
}
void display(struct node **head){ //O(n)
	struct node *temp;
	temp=*head;
	while(temp!=NULL){
		printf("%d --> ",temp->data);
	temp=temp->next;
	}
	printf("NULL\n");
}
int isEmpty(struct node **head){ //O(1)
	if (*head==NULL)
		return 1;
	return 0;
}
int length(struct node **head){ //O(n)
	int len=0;
	struct node *temp=*head;
	while(temp!=NULL){
		len++;
		temp=temp->next;
	}
	return len;
}
void insertAtPos(struct node **head,int pos,int val){ //O(p)
	struct node *newnode,*temp,*temp1;
	int i,len=length(&(*head));
	temp=*head;
	if (pos>len ||pos<1)
		return;
	if(pos==1){
		insertAtBegin(&(*head),val);
		return;	
	}	
	if(pos==len){
		insertAtEnd(&(*head),val);
		return;	
	}
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
	for (i=1;i<pos;i++)
	{
		save=temp;
		temp=temp->next;
	}
	int val=temp->data;
	save->next=temp->next;
	free(temp);
	return val;
}
int search(struct node **head,int val){ //O(n)
	struct node *temp;
	int pos=1;
	for(temp=*head;temp!=NULL;temp=temp->next){
		if(temp->data==val)
			return pos;
		else
			pos++;
	}
	return -1;
}
void sort(struct node **head){ //O(n^2)
	struct node *i,*j;
	int temp;
	for(i=*head;i!=NULL;i=i->next)
		for(j=i->next;j!=NULL;j=j->next)
			if(j->data < i->data){
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
}
void reverse(struct node **head){ //O(n)
	struct node *prev,*curr,*later;
	prev=NULL;
	curr=*head;
	if(*head==NULL)
		return;
	while(curr!=NULL){
		later=curr->next;
		curr->next=prev;
		prev=curr;
		curr=later;
	}
	*head=prev;
}
int main()
{
	int choice,val,pos;
	struct node *head=NULL;
	do
	{
		printf("\n\nMenu:-\n01. Insert End\n02. Display\n03. Display 2\n04. Insert Begin\n05. Insert position\n06. Length \n07. Delete at Begin\n08. Delete at End \n09. Delete at Position\n10. Sort\n11. Reverse\n12. Search\n13. Exit\nEnter your choice:\n");
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
				print(&head);
				break;
			case 4:
				printf("Enter data:\n");
				scanf("%d",&val);
				insertAtBegin(&head,val);
				break;
			case 5:
				printf("Enter position:\n");
				scanf("%d",&pos);
				printf("Enter data:\n");
				scanf("%d",&val);
				insertAtPos(&head,pos,val);
				break;
			case 6:
				printf("Lenght is : %d\n",length(&head));
				break;
			case 7:
				printf("%d deleted\n",deleteAtBegin(&head));
				break;
			case 8:
				printf("%d deleted\n",deleteAtEnd(&head));
				break;
			case 9:
				printf("Enter position:\n");
				scanf("%d",&pos);
				printf("%d deleted from %d position\n",deleteAtPos(&head,pos),pos);
				break;
			case 10:
				sort(&head);
				break;
			case 11:
				reverse(&head);
				break;
			case 12:
				printf("Enter value to search:: ");
				scanf("%d",&val);
				printf("found at: %d\n",search(&head,val));
				break;
		}
	}while(choice!=13);
	return 0;
}
