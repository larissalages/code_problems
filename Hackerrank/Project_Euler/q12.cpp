#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ///////////////////////seive
    ll size = 1e5+1;
    bool isprime[size];
    for(ll i=0;i<size;i++)
        isprime[i] = true;
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
    ll ans1 = s.size();
    ll prime[ans1],k = 0;
    for(auto it : s)
        prime[k++] = it;
    ll sizea = 50000;
    map <ll,ll> mp;
    mp[1] = 1;
    for(ll i=2;i<sizea;i++)
    {
        ll ke = 0,temp = (i*(i+1))/2;
        ll temp1 = temp;
        mp[temp1] = 1;
        map <ll,ll> m;
        while(temp != 1)
        {
            while((temp%prime[ke] == 0) && (temp != 0))
            {
                m[ke] += 1;
                temp /= prime[ke];
            }
            ke += 1;
        }
        for(auto it : m)
        {
            mp[temp1] *= (it.second+1);
        }
    }
    ///////////////////////
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(auto it : mp)
            {
                if(it.second >= (n+1))
                    {
                        cout<<it.first;
                        break;
                    }
            }
        cout<<"\n";
    }
    return 0;
}
