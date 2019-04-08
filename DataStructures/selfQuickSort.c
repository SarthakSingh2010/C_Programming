#include<stdio.h>
void swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
int partition(int a[],int l,int h){
	int p=a[h];
	int i=l-1;
	int j;
	for(j=l;j<=h-1;j++){
		if(a[j]<=p){
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[h]);
	return (i+1);
}
void quickSort(int a[],int l,int h){
	if(l<h){
		int p=partition(a,l,h);
		quickSort(a,l,p-1);
		quickSort(a,p+1,h);
	}
}
int main()
{
	int a[30],n,i;
	printf("Enter length: ");
	scanf("%d",&n);
	printf("Enter %d elements::\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	// T(n)= O(nlgn) avg O(n^2) worst ; S(n)=O(lgn); T(n)=T(k)+T(n-k-1)+O(n) k=#elem smaller than pivot
	quickSort(a,0,n-1); 
	// worst case: k=0, T(n)=T(n-1)+O(n) , best case: T(n)=2T(n/2)+O(n), avg T(n)=T(n/10)+T(9n/10)+O(n) =>O(nlgn)	
	printf("After Sorting::\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;
}
