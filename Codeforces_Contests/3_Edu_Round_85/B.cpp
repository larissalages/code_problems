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
        ll n;
        ld x;
        cin>>n>>x;
        ld a[n];
        for(ll i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        reverse(a,a+n);
        ll count = 0,sum = 0;
        while((count < n) && ((ld(count)+1.0)*x <= (sum + a[count])))
        {
            sum += a[count];
            count += 1;
        }
        cout<<count<<"\n";
    }
    return 0;   
}