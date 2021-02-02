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
    map <ll,ll> mp;
    for(ll i=0;i<size;i++)
        {
            if(a[i] > i)
                mp[i]++;
        }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n > 28123)
            cout<<"YES";
        else
        {
            ll flag = 0;
            for(auto it : mp)
                {
                    ll second = n - it.first;
                    if(mp.find(second) != mp.end())
                    {
                        flag = 1;
                        break;
                    }
                }
            if(flag)
                cout<<"YES";
            else
                cout<<"NO";
        }
    cout<<"\n";
    }
    ///////////////////////////
    return 0;
}
