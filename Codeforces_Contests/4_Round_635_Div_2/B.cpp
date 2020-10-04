/*
Author - Silent Knight
Institution - BIT Mesra
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll x,n,m;
        cin>>x>>n>>m;
        while(n != 0 && x > 20)
        {
            x /= 2;
            x += 10;
            n -= 1;
        }
        while(m != 0)
        {
            x -= 10;
            m -= 1;
        }
        if(x <= 0)
            cout<<"YES";
        else
        {
            cout<<"NO";
        }
    cout<<"\n";
    }
    return 0;   
}