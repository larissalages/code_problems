#include<bits/stdc++.h>

/*Author - Silent Knight
Institution - Birla Institute Of Technology, Mesra
*/

using namespace std;
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define mod 1000000007

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

ll fun1(string s,string k,ll n)
{
	ll i,j;
    ll a = 0,b = 0,x = 0;
    ll g[4]={0};
	ll p=1e9+7;
    ll sum=0;
	
	for(i=0;i<n;i++)
	{
		if(s[i]=='1')
		a++;
		if(k[i]=='1')
		b++;
	}
	
	if(a>b)
	{
		x=1;
	}
		g[0]=(a-b)*x;
		g[1]=(1-x)*(b-a);
		g[2]=(n-a)*x+(1-x)*(n-b);
		g[3]=b*x+(1-x)*a;
	 
		do{
		sum=(sum+ nCrModPFermat(n, g[0]+g[1], p))%p;

		g[0] += 1;
        g[1] += 1;
        g[2] -= 1;
        g[3] -= 1;
		}while(g[2]>=0 && g[3]>=0);
		
		return sum;
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

ll cycleLength(ll x) // in recurring decimal of 1/x
{
    if (x == 0)
        return 0;

    const unsigned int NotSeenYet = 0;
    vector <ll> lastPos(x, NotSeenYet);

    ll position = 1;
    ll dividend = 1;

    while (true)
    {

        ll remainder = dividend % x;
        if (remainder == 0)
        return 0;

        if (lastPos[remainder] != NotSeenYet)
        return position - lastPos[remainder];

        lastPos[remainder] = position;

        position += 1;
        dividend = remainder * 10;
    }
}

// UPSOLVED 
// Please refer to this youtube link.....his solutions and explanations are perfect : https://www.youtube.com/watch?v=0kr6YSroclg
//question language was complex.....find the pattern in solution
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //if u can't avoid it, enjoy it!!
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        map <ll,ll> mp; // to map elements to the index
        for(ll i=0;i<n;i++)
        {
            cin>>a[i];
            mp[a[i]] = i;
        }
        ll visited = 1,current = mp[1];
        while(visited <= n)
        {
            if((current == n) || (a[current] < visited))
                current = mp[visited];

            if(a[current] == visited)
            {
                current += 1;
                visited += 1;
            }
            else
                break;
        }

        if(visited == (n+1))
            cout<<"Yes";
        else
            cout<<"No";
    cout<<"\n";
    }
    return 0;
}