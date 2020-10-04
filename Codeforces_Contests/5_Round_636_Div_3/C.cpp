#include<bits/stdc++.h>

/*Author - Silent Knight
Institution - Birla Institute Of Technology, Mesra
*/

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
        ll flag = 1;
        ll max_neg = -1e17;
        ll max_pos = 0;
        vector <ll> v;
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
        }
        //checking for negative entries
        for(ll i=0;i<n;i++)
        {
            if(a[i] < 0)
            {
                max_neg = max(max_neg,a[i]);
            }
            else
                {
                    if(max_neg != -1e17)
                    {
                        v.push_back(max_neg);
                    }
                    max_neg = -1e17;
                }
        }
        if(max_neg != -1e17)
                    {
                        v.push_back(max_neg);
                    }
        for(ll i=0;i<n;i++)
        {
            if(a[i] > 0)
            {
                max_pos = max(max_pos,a[i]);
            }
            else
            {
                if(max_pos != 0)
                    v.push_back(max_pos);
                max_pos = 0;
            }
        }
        if(max_pos != 0)
                v.push_back(max_pos);
        ll sum = 0;
        for(auto it : v)
        {
            // cout<<it<<" ";
            sum += it;
        }
    cout<<sum<<"\n";
    }
    return 0;
}