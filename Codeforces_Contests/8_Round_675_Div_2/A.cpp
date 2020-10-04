// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (int i=a; i < n; i++) 
#define ll long long
#define pb push_back  
#define all(x) x.begin(), x.end() 
#define clr(x) memset(x, 0, sizeof(x)) 
#define sortall(x) sort(all(x)) 
typedef pair<ll, ll> pl; 
typedef vector<ll> vl; 
typedef vector<pl> vpii; 

int main() 
{  
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0); 
  
  ll t = 1; 
  cin >> t;
  
  while (t--) { 
    ll a,b,c;
    cin>>a>>b>>c;
    vl v={a,b,c};
    sortall(v);
    cout<<v[2]+v[1]-v[0]<<endl;
  } 
  return 0; 
} 