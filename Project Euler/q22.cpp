#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    map <string,ll> mp;
    for(ll i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        ll l = s.length();
        ll score = 0;
        for(ll j=0;j<l;j++)
        {
            score += (ll(s[j]) - ll('A') + 1);
        }
        mp[s] = score;
    }
    ll h = 1;
    map <string,ll> m1;
    for(auto it : mp)
    {
        m1[it.first] = (it.second*h);
        h += 1;
    }
    ll q;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        cout<<m1[s]<<"\n";
    }
    return 0;
}
