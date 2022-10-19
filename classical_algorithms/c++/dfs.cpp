// DFS for a directed graph 

#include<bits/stdc++.h>
using namespace std;
int v=4;
void DFS(int adjmat[4][4],bool visited[4],int src)
{
    visited[src]=true;
    cout<<src<<" ";
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false && adjmat[src][i]==1)
        {
            DFS(adjmat,visited,i);
        }
    }
}

int main()
{
    int e,v1,v2;     
    cin>>e ;                            // v and e are no. of vertices and edges respectively .
    int adjmat[4][4];                   //adjmat is the adjacency matrix 
    bool visited[v];                    // visited matrix indicates whether vertex has been visited or not 
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            adjmat[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        cin>>v1>>v2;
        adjmat[v1][v2]=1;
    }
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    int src=1;                          //src is the source vertex from which DFS should be started .
    DFS(adjmat,visited,src);
    return 0;
}