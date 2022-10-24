// DFS for a directed graph 

#include<stdio.h>
int v=4;
void DFS(int adjmat[4][4],int visited[4],int src)
{
    visited[src]=1;
    printf("%d ",src);
    for(int i=0;i<v;i++)
    {
        if(visited[i]==0 && adjmat[src][i]==1)
        {
            DFS(adjmat,visited,i);
        }
    }
}

int main()
{
    int e,v1,v2;     
    scanf("%d",&e);                     // v and e are no. of vertices and edges respectively .
    int adjmat[4][4];                   //adjmat is the adjacency matrix 
    int visited[v];                    // visited matrix indicates whether vertex has been visited or not 
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            adjmat[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        scanf("%d %d",&v1,&v2);
        adjmat[v1][v2]=1;
    }
    for(int i=0;i<v;i++)
    {
        visited[i]=0;
    }
    int src=1;                          //src is the source vertex from which DFS should be started .
    DFS(adjmat,visited,src);
    return 0;
}