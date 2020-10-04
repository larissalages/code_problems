#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll size = 1e5+100000;
    bool isprime[size];
    for(ll i=0;i<size;i++)
        isprime[i] = true;
    isprime[0] = false;
    isprime[1] = false;
    for(ll i=2;i*i<size;i++)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<size;j+=i)
            {
                isprime[j] = false;
            }
        }
    }
    set <ll> s;
    for(ll i=0;i<size;i++)
    {
        if(isprime[i])
        {
            s.insert(i);
        }
    }
    ll sizea = s.size();
    ll a[sizea],k = 0;
    for(auto it : s)
    {
        a[k++] = it;
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<a[n-1]<<"\n";
    }
    return 0;
}
