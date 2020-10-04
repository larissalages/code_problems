/*
Author - Silent Knight
Institution - BIT Mesra
*/
#include<bits/stdc++.h>

using namespace std;
typedef long long int ll; 
typedef long double ld;
#define pb push_back

ll modInverse(ll n,ll p) 
{ 
    ll x = n;
    ll y = p-2;
    ll res = 1;   
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res;  
} 
  

ll nCrModPFermat(ll n,ll r,ll p)  //if mod value is prime 
{ 
   if (r == 0) 
      return 1; 
    
    ll fac[n+1]; 
    fac[0] = 1; 

    for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]*modInverse(fac[r], p) % p*modInverse(fac[n-r], p) % p) % p; 
} 

ll nCrModP(ll n,ll r,ll p)          //normal iterative solution for all values of mod
{
    r = min(r,n-r);
    ll c[r+1];
    memset(c,0,sizeof(c));
    c[0] = 1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=min(i,r);j>0;j--)
        {
            c[j] = (c[j] + c[j-1])%p;
        }
    }
    return c[r];
}

void PacalCombinations(ll size)
{
    ll a[size][size];
    for(ll i=0;i<size;i++)
    {
        for(ll j=0;j<size;j++)
            a[i][j] = 0;
    }
    a[0][0] = 1;
    for(ll i=1;i<size;i++)
    {
        for(ll j=0;j<=i;j++)
        {
            if(j == 0 || j == i)
                a[i][j] = 1;
            else
                a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
}

ll power(ll x, ll y, ll p)  
{  
    ll res = 1;     
    x = x % p; 
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % p;  
  
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
}
 
const ll N = 6e5+101;
const ll maxN = 1e17;
 
ll n, k;
ll cnt[N];
ll maxi[N], mini[N];
ll a[N];
 
int main()  
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) 
    {
        cin>>n>>k;
        for(ll i=1;i<=n;i++) 
            cin>>a[i];
        for(ll i=1;i<=n/2;i++)
        {
            maxi[i] = max(a[i], a[n - i + 1]) + k;
            cnt[a[i] + a[n - i + 1]] += 1;
            mini[i] = min(a[i], a[n - i + 1]);
        }
        sort(maxi + 1, maxi + n / 2 + 1);
        sort(mini + 1, mini + n / 2 + 1);
        ll ans = 1e18;
        for(ll i=1;i<=2*k;i++)  
        {
            ll val = i;
            ll position1 = lower_bound(maxi + 1, maxi + n / 2 + 1, val) - maxi - 1;
            ll position2 = lower_bound(mini + 1, mini + n / 2 + 1, val) - mini;
 
            position2 = n/2 - position2 + 1;
 
            ll tmp = (position1 + position2) * 2 + (n / 2 - position1 - position2) - cnt[ val ];
            ans = min(ans, tmp);
        }
        for(ll i=1;i<=n/2;i++)
            cnt[ a[i] + a[n - i + 1] ] -= 1;
        cout<<ans<<"\n";
    }
}