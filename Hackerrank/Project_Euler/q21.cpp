#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ///////////////////////////seive
    ll size = 1e6+1;
    ll a[size];
    for(ll i=0;i<size;i++)
        a[i] = 1;
    a[0] = 0;
    a[1] = 0;
    for(ll i=2;i<size;i++)
    {
        for(ll j=2*i;j<size;j+=i)
        {
            a[j] += i;
        }
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll sum = 0,ans1,ans2;
        for(ll i=2;i<=n;i++)
        {
            ans1 = a[i];
            ans2 = a[ans1];
            if((ans2 == i) && (ans1 != ans2))
            {
                // cout<<ans1<<" "<<ans2<<"\n";
                sum += i;
            }
        }
        cout<<sum<<"\n";
    }
    ///////////////////////////
    return 0;
}
