#include<stdio.h>

// no. of vertices =5
// Adjacency matrix
// starting vertex: 1

int G[10][10],Q[10],visited[10],n,f=0,r=-1;
void bfs(int v){
	int i,j;
	for(i=1;i<=n;i++)
		if(G[v][i]==1 && visited[i]==0)
			Q[++r]=i;
		if(f<=r){
			visited[Q[f]]=1;
			bfs(Q[f++]);
		}
}
int main(){
	int i,j,v;
	printf("Enter number of veritces:: ");
	scanf("%d",&n);
	printf("Enter Adjacency Matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&G[i][j]);
	printf("Enter starting vertex:: ");
	scanf("%d",&v);
	bfs(v);
	printf("Reachable nodes: ");
	for(i=1;i<=n;i++)
		if(visited[i]==1)
			printf("%d ",i);
	return 0;
}
