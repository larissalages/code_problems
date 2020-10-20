//Somos insignificantes. Por mais que você programe sua vida, a qualquer momento tudo pode mudar.
// If you have God on your side,everything becomes clear

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)
/*void Sieve(int n) 
{ 
    
    //bool prime[n+1]; 
    //memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    
} */
/* struct cmp{
    bool operator()(const pair<int,int>& v1,const pair<int,int>& v2) const{
    	
    }};*/
 long long binpow(long long a, long long b) {
    a %=MOD;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    res=res%MOD;
    return res;
}
   



void solve() {
    ll n,k;
    cin>>n>>k;
    ll freq[101];
    ll a[n];
    set<ll>s;
    for(int i=0;i<n;i++){cin>>a[i];
    s.insert(a[i]);}
    if(k==1){
        if(a[n-1]==a[0]){cout<<1<<endl;
        return;}
        else {
            cout<<-1<<endl;
            return;
        }
    }
    else{
        if(s.size()<=k){
            cout<<1<<endl;
            return;
        }
        vector<ll>v;
        for(auto i:s)v.push_back(i);
            ll j=k;
            for(ll i=2;i<=10001;i++)
            {
                j+=(k-1);
                if(j>=v.size())
                {
                    cout<<i<<endl;
                    return;}
            }


      
        



    }
    


    


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}