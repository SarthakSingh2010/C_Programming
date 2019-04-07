#include<stdio.h>
#define CAP 100

int a[CAP],top=-1;

void insert(int val)  //O(1)
{
	if(top>=CAP-1){
		printf("\nOverFlow\n");
		return;
	}
	else{
		top++;
		a[top]=val;
	}
}
int del() //O(1)
{
	int item;
	if(top<0){
		printf("\nUnderFlow\n");
		return -1;
	}
	else{
		item=a[top];
		top--;
		return item;
	}
}
int empty() //O(1)
{
	return (top<0)?1:0;
}
int full() //O(1)
{
	return (top>=CAP)?1:0;
}
void display() //O(n)
{
	int i=top;
	printf("\n\nTop --> ");
	while(i!=-1){
		printf("%d ",a[i]);
		i--;
	}
	printf("\n\n");
}
int main()
{
	int ch,val;
	do{
		printf("\n\nMenu::\n01. Insert\n02. Delete\n03. Empty\n04. Full\n05. Display\n06. Exit\nEnter your choice:: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter value:: ");
				scanf("%d",&val);
				insert(val);
			break;
			case 2:
				val=del();
				if(val!=-1)
					printf("%d deleted\n",val);
			break;
			case 3:
				if(empty())
					printf("Empty\n");
				else
					printf("Not Empty\n");
			break;
			case 4:
				if(full())
					printf("Full\n");
				else
					printf("Not Full\n");
			break;
			case 5:
				display();
			break;
		}
	}while(ch!=6);
	return 0;
}
