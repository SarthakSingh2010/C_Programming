#include<stdio.h>
int linearSearch(int a[],int n,int k){ //O(n)
	int i;
	for(i=0;i<n;i++)
		if(a[i]==k)
			return i;
	return -1;
}
int binarySearch(int a[],int l,int u,int k){ //O(lgn) only work for sorted array
	int mid;
	if(l<=u){
		mid=(l+u)/2;
		if(a[mid]==k)
			return mid;
		if (a[mid]>k)
			return binarySearch(a,l,mid-1,k);
		if (a[mid]<k)
			return binarySearch(a,mid+1,u,k);
	}
	return -1;
}
int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	printf("%d\n",linearSearch(a,10,7));
	printf("%d\n",linearSearch(a,10,11));
	printf("%d\n",binarySearch(a,0,9,7));
	printf("%d\n",binarySearch(a,0,9,11));
	return 0;
}
