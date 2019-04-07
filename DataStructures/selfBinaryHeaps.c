#include<stdio.h>
void maxHeapify(int a[],int i, int n) //O(lg n) [Height of nearly Complete Binary Tree]
{ // a= array , n =len(array) , i =index of elem to be adjusted
	int left,right,largest,t;
	left=2*i+1;
	right=2*i+2;
	largest=i;
	if(left>=n)
	return;
	else
	{
		if(left<n && a[left]>a[largest])
		largest=left;
		if(right<n && a[right]>a[largest])
		largest=right;
		if(largest!=i)
		{
			t=a[largest];
			a[largest]=a[i];
			a[i]=t;
			maxHeapify(a,largest,n); // chk for subtree
		}
	}
}
void buildMaxHeap(int a[],int n) //O(n)
{ //we do n/2 because elem A[n/2+1 .... n] are all leaves.
  // And all leaves are max heap.
	int i;
	for(i=n/2;i>=0;i--)
	maxHeapify(a,i,n);
}
//Max Heap: all parent key >= child key
//Min Heap: all parent key <= child key
// for min heap find smallest instead of largest

void heapSort(int a[],int n) //O(nlgn)  , space: O(1)
{ 
	int i,t;
	buildMaxHeap(a,n);
	for(i=n-1;i>=0;i--){
		t=a[i]; // swap max elem with last index
		a[i]=a[0]; 
		a[0]=t;
		maxHeapify(a,0,i-1); //then call max heapify on n-1 elem
	}		
}
void display(int a[],int n) //O(n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
}
int main()
{
	int a[]={12,11,13,5,6,7};
	int n=sizeof(a)/sizeof(a[0]);
	buildMaxHeap(a,n);
	printf("Max Heap:: ");
	display(a,n);
	printf("After sorting:: ");
	heapSort(a,n);
	display(a,n);
	return 0;
}
