#include<bits/stdc++.h>
#define ll long long 
using namespace std;
#define  N 251
pair<ll,ll>mm[]{{-1,-1},{-1,0},{0,0},{0,1},{1,0},{1,1},{-1,1},{1,-1},{0,-1}};
bool isvalid(ll i,ll j,ll n,ll m)
{
    return(i>=0&&j>=0&&i<n&&j<m);
}
void dfs(ll adj[N][N],ll vis[N][N],ll n,ll m,ll i,ll j,ll &cnt)
{
    vis[i][j]=1;
    cnt++;
    for(pair<ll,ll> x:mm)
    {
        ll nx=i+x.first,ny=j+x.second;
        if(isvalid(nx,ny,n,m)&&vis[nx][ny]==0&&adj[nx][ny]==1)
        dfs(adj,vis,n,m,nx,ny,cnt);
    }
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll adj[N][N];
        ll vis[N][N];
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                cin>>adj[i][j];
                vis[i][j]=0;
            }
            
        }
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                ll cnt=0;
                if(vis[i][j]==0&&adj[i][j]==1)
                dfs(adj,vis,n,m,i,j,cnt);
                ans=max(ans,cnt);
            }
        }
        cout<<ans<<"\n";
    }
}
