// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long
#define pb push_back 
#define all(x) x.begin(), x.end() 
#define clr(x) memset(x, 0, sizeof(x)) 
#define sortall(x) sort(all(x)) 
typedef pair<ll, ll> pl; 
typedef vector<ll> vl;  
const ll mod=1000000007;
ll power(ll x,ll y,ll m){if(y==0)return 1;ll p=power(x,y/2,m)%m;p=(p*p)%m;return (y%2==0)?p:(x*p)%m;}

int main() 
{  
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0); 

  ll t = 1; 
  // cin >> t;

  while (t--) { 
    	string s;
      cin >> s;
      ll ans=0;
      ll n=s.length();
      ll tmp=0;
      for(ll i=n-2;i>=0;--i)
      {
        ll t=(s[i]-'0');
        tmp+=(power(10,n-i-2,mod)*(n-i-1))%mod;
        tmp%=mod;
        ans+=((t*tmp)%mod);
        ans%=mod;
      }
      tmp=0;
      fi(i,1,n)
      {
        ll t=(s[i]-'0');
        tmp+=i;
        tmp%=mod;
        ans+=(((t*tmp)%mod)*power(10,n-i-1,mod))%mod;
        ans%=mod;
      }
      cout << ans << endl;
  } 
  return 0; 
} 
