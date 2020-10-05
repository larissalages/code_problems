#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
 
long long numberOfDigits(long long n) 
{ 
    if (n == 1) 
        return 1; 

    long double d = (n * log10(1.6180339887498948)) - 
                    ((log10(5)) / 2); 
  
    return ceil(d); 
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll size = 24000;
    ll a[size];
    for(ll i=1;i<size;i++)
    {
        a[i] = numberOfDigits(i);
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans = lower_bound(a,a+size,n) - a;
        cout<<ans<<"\n";
    }

    ///////////////////////////
    return 0;
}
