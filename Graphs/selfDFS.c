#include<stdio.h>

//no. of vertices = 5
//value of vertex= 1 2 3 4 5
//adjacency matrix

int G[10][10],visited[10],n,vertex[10];

void dfs(int i){
	int j;
	printf("%d ",vertex[i]);
	visited[i]=1;
	for(j=0;j<n;j++)
		if(visited[j]==0 && G[i][j]==1)
			dfs(j);
}

int main(){
	int i,j;
	printf("Enter number of veritces:: ");
	scanf("%d",&n);
	printf("Enter values of vertex:: ");
	for(i=0;i<n;i++)
		scanf("%d",&vertex[i]);
	printf("Enter Adjacency Matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
			
	for(i=0;i<n;i++)
	visited[i]=0;
	printf("Path Traversed: ");
	dfs(0);
	return 0;
}
