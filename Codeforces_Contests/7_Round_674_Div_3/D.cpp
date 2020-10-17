#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define rf(i,n,a) for(int i=n ; i>=a ; i--)
#define F first
#define S second
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;

const int inf = 1e9;
const int inf64 = 1e18;
const int MOD = inf + 7;


void solve(){
   int n;
   cin >> n;

   int a[n];
   f(i,0,n) cin >> a[i];

   set<int>s;
   s.insert(0);

   int ans = 0, sum = 0;
   f(i,0,n){
      sum += a[i];
      if(s.find(sum) != s.end()){
         s.clear();
         ans++;
         sum = a[i];
         s.insert(0);
      }
      s.insert(sum);
   }
   cout << ans << "\n";
}

int32_t main(){
   fast;
   int t = 1;
   // cin >> t;
   while(t--)  solve();   
}
