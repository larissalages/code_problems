#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define N 100000
using namespace std;
vector<ll>adj[N];   //storing the list
vector<ll>vis(N);   
bool cycle(ll curr,ll par)
{
    ll res=0;
    vis[curr]=1;
    for(auto neb:adj[curr])
    {
        if(neb==par)
        continue;
        if(vis[neb]==1)
        return 1;
        else
        res|=cycle(neb,curr);
    }
    return res;
    
}
int main()
{
    ll n,m;    //no.of nodes and no. of connection
    cin>>n>>m;
  
    for(ll i=1;i<=m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        
    }
    for(ll i=1;i<=n;i++)
    vis[i]=0;
    ll flag=0;
    for(ll i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            flag|=cycle(i,0);
        }
    }
    if(flag==1)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}
