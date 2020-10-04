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
        vector <pair<ll,ll>> v;
        ll a,b;
        for(ll i=0;i<n;i++)
        {
            cin>>a>>b;
            v.push_back(make_pair(a,b));
        }
        ll attempt = 0, clear = 0;
        ll flag = 0;
        a = v[0].first;
        b = v[0].second;
        if(b > a)
            flag = 1;
        attempt = a;
        clear = b;
        for(ll i=1;i<n;i++)
        {
            a = v[i].first;
            b = v[i].second;
            if(!((a >= attempt) && (b >= clear) && (b <= a) && (a-attempt >= b - clear)))
            {
                flag = 1;
                break;
            }
            attempt = a;
            clear = b;
        }
        if(flag)
            cout<<"NO";
        else
            cout<<"YES";
    cout<<"\n";
    }
    return 0;   
}