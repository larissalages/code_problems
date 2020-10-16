// Author:Nishtha

#include <bits/stdc++.h> 
using namespace std; 
  
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long
#define pb push_back 
#define mp make_pair 
#define F first 
#define S second 
#define all(x) x.begin(), x.end() 
#define clr(x) memset(x, 0, sizeof(x)) 
#define sortall(x) sort(all(x)) 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pl; 
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<pii> vpii; 

ll getMaxArea(ll hist[], ll n){
  // to store indices of 
  stack<ll>st; 
  ll max_area=0,top,area_with_top,i=0;
  while(i<n){
    if(st.empty() || hist[st.top()]<=hist[i]){
      st.push(i++);
    }
    else{
      top=st.top();
      st.pop();
      area_with_top=hist[top]*(st.empty()? i: i-st.top()-1);
      if(area_with_top>max_area){
        max_area=area_with_top;
      }
    }
  }
  while(st.empty()==false){
    top=st.top();
    st.pop();
    area_with_top=hist[top]*(st.empty()?i:i-st.top()-1);
    if(area_with_top>max_area){
      max_area=area_with_top;
    }
  }
  return max_area;
}

// Drive Code 
int main() 
{  
  // #ifndef ONLINE_JUDGE 
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout); 
  // #endif
  // Fast Input/Output 
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0); 

  // Test Cases 
  ll t = 1; 
  // cin >> t;

  while (t--) { 
    ll n;
    cin>>n;
    ll hist[n];
    fi(i,0,n)
    cin>>hist[i];
    cout<<getMaxArea(hist, n)<<endl;
  } 

  return 0; 
} 
