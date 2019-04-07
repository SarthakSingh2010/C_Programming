#include<stdio.h>
void swap(int a[],int i,int j)
{
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
}
void bubbleSort(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
				swap(a,j,j+1);
}
void insertionSort(int a[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
		for(j=i;j>0;j--)
			if(a[j-1]>a[j])
				swap(a,j-1,j);
}
void selectionSort(int a[],int n)
{
	int i,j,p;
	for(i=0;i<n-1;i++){
		p=i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[p])
				p=j;
		}
		swap(a,p,i);
	}
}
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main()
{
	int a1[]={9,6,4,1,2,3,5,8,7,0};
	int a2[]={9,6,4,1,2,3,5,8,7,0};
	int a3[]={9,6,4,1,2,3,5,8,7,0};
	
	bubbleSort(a1,10);
	selectionSort(a2,10);
	insertionSort(a3,10);
	
	display(a1,10);
	display(a2,10);
	display(a3,10);
	
	return 0;
}
