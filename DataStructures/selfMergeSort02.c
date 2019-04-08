#include<stdio.h>
void mergeSort(int a[],int l,int u);
void merge(int a[],int l1,int u1,int l2,int u2);

int main()
{
	int a[30],n,i;
	printf("Enter length: ");
	scanf("%d",&n);
	printf("Enter %d elements::\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	mergeSort(a,0,n-1); // T(n)= O(nlgn) , S(n)=O(n), T(n)=2T(n/2)+O(n)	
	printf("After Sorting::\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;
}
void mergeSort(int a[],int l,int u){
	int mid;
	if(l<u){
		mid=(l+u)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,u);
		merge(a,l,mid,mid+1,u);
	}
}
void merge(int a[],int l1,int u1,int l2,int u2){
	int t[60]; //array used for merging
	int i,j,k;
	i=l1;
	j=l2;
	k=0;
	while(i<=u1 && j<=u2){
		if(a[i]<a[j])
			t[k++]=a[i++];
		else
			t[k++]=a[j++];
	}
	while(i<=u1)
		t[k++]=a[i++];
	while(j<=u2)
		t[k++]=a[j++];
	for(i=l1,j=0;i<=u2;i++,j++)
	a[i]=t[j]; //Transfer elements
}
