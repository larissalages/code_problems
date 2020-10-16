#include<bits/stdc++.h>
using namespace std;

#define int long long
#define f(i,a,n) for(int i=a ; i<n ; i++)
#define rf(i,n,a) for(int i=n ; i>=a ; i--)
#define F first
#define S second
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int inf = 1e9;
const int inf64 = 1e18;
const int MOD = inf + 7;

void solve(){
   int n;
   cin >> n;

   int a[3] = {0};
   a[0] = n/3;
   n %= 3;

   if(n == 2 && a[0]){
      a[0]--, a[1]++;
      n = 0;
   }

   if(n == 1 && a[0] > 1){
      a[0] -= 2, a[2]++;
      n = 0;
   }

   if(n){
      cout << "-1\n";
   }
   else{
      cout << a[0] << " " << a[1] << " " << a[2] << "\n";
   }
}

int32_t main(){
   fast;
   int t = 1;
   cin >> t;
   while(t--)  solve();   
}
