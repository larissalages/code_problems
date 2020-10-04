#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

const ll size = 5000000 + 1;
ll dp[size];

ll i_love_you(ll n)
{
    if((n < size) && (dp[n] != 0))
        return dp[n];
    else
    {
        if(n%2 == 0)
            return (1 + i_love_you(n/2));
        else
            return (1 + i_love_you(3*n + 1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    dp[1] = 1;
    for(ll i=2;i<size;i++)
       {
           dp[i] = i_love_you(i);
       } 
    ll maxi = -1;
    ll index = 1;
    for(ll i=1;i<size;i++)
    {
        if(maxi <= dp[i])
        {
            maxi = dp[i];
            index = i;
        }
        dp[i] = index;
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<dp[n]<<"\n";
    }
    return 0;
}
