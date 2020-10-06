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
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll maxi = -1;
        for(ll i=0;i<=(n-k);i++)
        {
            ll prod = 1;
            for(ll j=i;j<(i+k);j++)
            {
                prod *= (s[j]-'0');
            }
            // cout<<prod<<"\n";
            maxi = max(prod,maxi);
        }
        cout<<maxi<<"\n";
    }
    return 0;
}
