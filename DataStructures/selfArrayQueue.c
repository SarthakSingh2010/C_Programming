#include<stdio.h>
#define MAX 100

int arr[MAX],front=-1,rear=-1;

void insert(int val) //O(1)
{
	if(rear==MAX-1)
	printf("\nOverflow\n");
	else{
		if(front==-1)
		front=0;
		rear++;
		arr[rear]=val;
	}
}
void del() //O(1)
{
	if(front==-1 || front>rear)
	printf("\nUnderflow\n");
	else{
		printf("%d deleted\n",arr[front]);
		front++;
	}
}
void display() //O(n)
{
	int i;
	if (front==-1)
	printf("\nEmpty Queue\n");
	else{
		for(i=front;i<=rear;i++)
		printf("%d ",arr[i]);
		printf("\n");
	}
}
int main()
{
	int ch,item;
	do{
		printf("\n\nMenu::\n01. Insert\n02. Delete\n03. Display\n04. Exit\nEnter your choice:: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter value:: ");
				scanf("%d",&item);
				insert(item);
			break;
			case 2:
				del();
			break;
			case 3:
				display();
			break;
		}
	}while(ch!=4);
	return 0;
}
