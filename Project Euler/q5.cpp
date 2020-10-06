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
        ll ans = 1,prod = 1;
        ll n;
        cin>>n;
        for(ll i=2;i<=n;i++)
        {
            ans = __gcd(i,prod);
            prod /= ans;
            prod *= i;
        }
        cout<<prod<<"\n";
    }
    return 0;
}
