// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 
#define ll long long
#define pb push_back 
#define mp make_pair 
#define F first 
#define S second 
#define all(x) x.begin(), x.end() 
#define clr(x) memset(x, 0, sizeof(x)) 
#define sortall(x) sort(all(x)) 
typedef pair<ll, ll> pl; 
typedef vector<ll> vl; 

int main() 
{  
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0); 

  ll t = 1; 
  cin >> t;

  while (t--) { 
    ll n,m,ans=0;
    cin>>n>>m;
    vl v[n];
    fi(i,0,n){
      fi(j,0,m){
        ll x;cin>>x;
        v[i].pb(x);
      }
    }
    fi(i,0,n/2){
      fi(j,0,m/2){
        vector<ll> v1={v[i][m-j-1],v[i][j],v[n-1-i][j],v[n-1-i][m-1-j]};
        sortall(v1);
        ll mean=v1[1];
        fi(i,0,v1.size())
        ans+=abs(mean-v1[i]);
      }
    }
    if(n%2){
      fi(i,0,m/2){
        ans+=abs(v[n/2][i]-v[n/2][m-1-i]);
      }
    }
    if(m%2){
      fi(i,0,n/2){
        ans+=abs(v[i][m/2]-v[n-1-i][m/2]);
      }
    }
    cout<<ans<<endl;
  } 

  return 0; 
} 