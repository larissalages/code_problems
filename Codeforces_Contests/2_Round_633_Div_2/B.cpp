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
        ll a[n];
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        stack <ll> s;
        for(ll i=0;i<n;i++)
        {
            ll index = (n-i-1);
            if((index <= i) && (n%2 == 0))
                break;
            else if((index == i) && (n%2 != 0))
            {
                s.push(a[i]);
                break;
            }
            s.push(a[i]);
            s.push(a[index]);
        }
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    cout<<"\n";
    }
    return 0;
}