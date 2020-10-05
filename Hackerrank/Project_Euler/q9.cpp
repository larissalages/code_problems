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
        if(n < 12)
            cout<<-1;
        else 
        {
            ll maxi = -1;
            for(ll i=1;i<=n/3;i++)
            {
                ll b = ((n*n) - 2*n*i)/((2*n) - (2*i));
                ll c = n-i-b;
                if((i*i)+(b*b) == (c*c))
                {
                    maxi = max(maxi,(i*b*c));
                }
            }
            cout<<maxi;
        }
    cout<<"\n";
    }
    return 0;
}
