#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ///////////////////////////////////////////seive
    ll size = 1e6+1;
    bool isprime[size];
    for(ll i=0;i<size;i++)
    {
        isprime[i] = true;
    }
    isprime[0] = isprime[1] = false;
    for(ll i=2;i*i<size;i++)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<size;j+=i)
                isprime[j] = false;
        }
    }
    set <ll> s;
    for(ll i=0;i<size;i++)
    {
        if(isprime[i])
            s.insert(i);
    }
    ll sizea = s.size();
    ll a[sizea],b[sizea],f = 0;
    for(auto it : s)
    {
        a[f++] = it;
    }
    b[0] = a[0];
    for(ll i=1;i<sizea;i++)
    {
        b[i] = a[i];
        b[i] += b[i-1];
    }
    ///////////////////////////////////////////
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll index = lower_bound(a,a+sizea,n) - a;
        if(a[index] != n)
        {
            index -= 1;
        }
        cout<<b[index]<<"\n";
    }
    return 0;
}
