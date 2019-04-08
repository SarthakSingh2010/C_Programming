#include<stdio.h>
void mergeSort(int a[],int l,int u);
void merge(int a[],int l,int mid,int u);

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
		merge(a,l,mid,u);
	}
}
void merge(int a[],int l,int mid,int u){
	int i,j,k;
	int n1=mid-l+1;
	int n2=u-mid;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	L[i]=a[l+i];
	for(j=0;j<n2;j++)
	R[j]=a[mid+1+j];
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2){
		if(L[i]<R[j])
			a[k++]=L[i++];
		else
			a[k++]=R[j++];
	}
	while(i<n1)
		a[k++]=L[i++];
	while(j<n2)
		a[k++]=R[j++];
}
