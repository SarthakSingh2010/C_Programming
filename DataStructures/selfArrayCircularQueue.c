#include<stdio.h>
#define MAX 100
#define INT_MIN -9999

int a[MAX]={[0 ... MAX-1]=INT_MIN};
int rear=MAX-1,front=0,len=0;

void insert(int val) //O(1)
{
	if(len==MAX)
	{
		printf("\nQueue Full\n");
		return;
	}
	rear=(rear+1)%MAX;
	a[rear]=val;
	len++;
	printf("\n %d is added\n",val);
}
void del() //O(1)
{
	if(len==0){
		printf("\nQueue Enpty\n");
		return;
	}
	printf("\n%d is deleted\n",a[front]);
	a[front]=INT_MIN;
	front=(front+1)%MAX;
	len--;
}
void display() //O(n)
{
	int i;
	for(i=0;i<MAX;i++)
	{
		if(a[i]!=INT_MIN)
		printf("%d ",a[i]);
	}
	printf("\nFront: %d\nRear: %d\n",a[front],a[rear]);
	printf("\nLength: %d\n",len);
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
