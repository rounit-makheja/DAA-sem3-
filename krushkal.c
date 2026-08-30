#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



void kruskalMST(int **cost, int V) {

	int p[V], e[V*V][3], n=0, count=0, total=0;

for(int i=0;i<V;i++) p[i]=i;

for(int i=0;i<V;i++)
    for(int j=i+1;j<V;j++)
        if(cost[i][j]!=9999){
            e[n][0]=i;
            e[n][1]=j;
            e[n++][2]=cost[i][j];
        }

for(int i=0;i<n-1;i++)
    for(int j=0;j<n-i-1;j++)
        if(e[j][2]>e[j+1][2]){
            int t=e[j][0]; e[j][0]=e[j+1][0]; e[j+1][0]=t;
            t=e[j][1]; e[j][1]=e[j+1][1]; e[j+1][1]=t;
            t=e[j][2]; e[j][2]=e[j+1][2]; e[j+1][2]=t;
        }

for(int i=0;i<n && count<V-1;i++){
    int a=e[i][0],b=e[i][1],x=a,y=b;

    while(p[x]!=x) x=p[x];
    while(p[y]!=y) y=p[y];

    if(x!=y){
        printf("Edge %d:(%d, %d) cost:%d\n",count,a,b,e[i][2]);
        p[y]=x;
        total+=e[i][2];
        count++;
    }
}

printf("Minimum cost= %d\n",total);
	
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}
