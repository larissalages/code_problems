/*
Author - Silent Knight
Institution - BIT Mesra
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++)
            cin>>a[i];
        ll maxi = INT_MIN;
        ll max_diff = INT_MIN;
        for(ll i=0;i+1<n;i++)
        {
            if(a[i] > a[i+1])
            {
                maxi = max(maxi,a[i]);
                max_diff = max(max_diff,(maxi - a[i+1]));
            }
        }
        if(maxi == INT_MIN)
            cout<<0;
        else
        {
            ll ans = log2(max_diff) + 1;
            cout<<ans;
        }
        cout<<"\n";
    }
    return 0;
}