// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long

int main() 
{  
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0); 

  ll t = 1; 
  cin >> t;

  while (t--) { 
    ll n;
    cin>>n;
    ll a[n];
    int flg=0;
    ll prev;
    fi(i,0,n){
      cin>>a[i];
    }
    prev = a[0];
    fi(i,1,n){
      if(a[i]!=prev){
          flg=1;
          break;
      } 
      //break;
    }
    if(flg)
    cout<<1<<endl;
    else cout<<n<<endl;
  } 
  return 0; 
} 
