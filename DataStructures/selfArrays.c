#include<stdio.h>
int a[20],b[20],c[40];
int m,n,p,val,i,j,key,pos,temp;
void create(){ //O(n)
	printf("Enter Length: ");
	scanf("%d",&n);
	printf("Enter Elements:-\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}
void display(){ //O(n)
	printf("The elements are:-\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void insert(int pos,int val){ //O(n)
	for(i=n-1;i>=pos;i--)
		a[i+1]=a[i];
	a[pos]=val;
	n++;
}
int del(int pos){ //O(n)
	val=a[pos];
	for(i=pos;i<n-1;i++)
		a[i]=a[i+1];
	n--;
	return val;
}
int search(int val){ //O(n)
	for(i=0;i<n;i++)
		if(a[i]==val)
			return i;
	return -1;
}
void sort(){ //O(n^2)
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(a[j]<a[i]){
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
}
void merge(){ //O(m+n)
	printf("Enter size of second array: ");
	scanf("%d",&m);
	printf("Enter elements:\n");
	for(i=0;i<m;i++)
		scanf("%d",&b[i]);
	j=0;
	for(i=0;i<n;i++)
		c[j++]=a[i];
	for(i=0;i<m;i++)
		c[j++]=b[i];
	p=n+m;
	printf("After merge:\n");
	for(i=0;i<p;i++)
		printf("%d ",c[i]);
	printf("\n");
}
int main()
{
	int choice;
	do{
		printf("\n\nMenu:\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Sort\n6. Search\n7. Merge\n8. Exit\nEnter your choice:: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				printf("Enter position:: ");
				scanf("%d",&pos);
				printf("Enter value:: ");
				scanf("%d",&val);
				insert(pos,val);
				break;
			case 4:
				printf("Enter position:: ");
				scanf("%d",&pos);
				printf("%d deleted\n",del(pos));
				break;
			case 5:
				sort();
				break;
			case 6:
				printf("Enter value:: ");
				scanf("%d",&val);
				printf("%d found at index %d\n",val,search(val));
				break;	
			case 7:
				merge();
				break;
		}
	}while(choice!=8);
	return 0;
}
