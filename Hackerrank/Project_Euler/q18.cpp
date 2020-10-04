#include<bits/stdc++.h>

#define pb push_back
#define bigint int64_t

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    /////////////////////////////////////////////////////////////////sieve
    ll size = 1e5;
    bool isprime[size];
    for(ll i=0;i<size;i++)
        isprime[i] = true;
    isprime[0] = isprime[1] = false;
    for(ll i=0;i<size;i++)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<size;j+=i)
            {
                isprime[j] = false;
            }
        }
    }
    //////////////////////////////////////////////////////////////////////
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll check = n*(n+1);
        check /= 2;
        ll arr[check];
        for(ll i=0;i<check;i++)
            cin>>arr[i];
        ll row = n,col = 2*n - 1;
        ll a[row][col];
        for(ll i=0;i<row;i++)
        {
            for(ll j=0;j<col;j++)
                a[i][j] = -1;
        }
        ll temp = n-1,k = 0;
        for(ll i=0;i<row;i++)
        {
            for(ll j=(temp-i);j<=(temp+i);j+=2)
            {
                a[i][j] = arr[k++];
            }
        }
        ll ans1,ans2;
        for(ll i=(n-2);i>=0;i--)
        {
            for(ll j=0;j<col;j++)
            {
                if(a[i][j] != -1)
                {
                    ans1 = a[i][j] + a[i+1][j-1];
                    ans2 = a[i][j] + a[i+1][j+1];
                    a[i][j] = max(ans1,ans2);   
                }
            }
        }
        cout<<a[0][temp]<<"\n";
    }
    //////////////////////////////////////////////////////////////////////
    return 0;
}
