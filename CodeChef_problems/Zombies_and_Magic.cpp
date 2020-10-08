#include<bits/stdc++.h>
#define ll long long
#define N 100000
using namespace std;

vector<ll>adj[N];
vector<ll>vis(N);
void dfs(ll curr)
{
    vis[curr]=1;
    for(auto neb:adj[curr])
    {
        if(vis[neb]==0)
        dfs(neb);
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    ll z;
    cin>>z;
    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(ll i=0;i<n;i++)
    vis[i]=0;
    vis[z]=1;
    if(z==0)dfs(1);
    else
    dfs(0);
    ll flag=0;
    for(ll i=0;i<n;i++)
    {
        if(!vis[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    cout<<"yes\n";
    else
    cout<<"no\n";
    
}
