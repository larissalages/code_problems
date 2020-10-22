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
    ll n,l;
    cin>>n>>l;
    double a[n],b[n];
    for(int i=0;i<n;i++){cin>>a[i];
    b[i]=a[i];}
    sort(b,b+n,greater<ll>());
    double t=0,v1=1,v2=1;
    double pos1=0,pos2=l;
    ll cur1=0,cur2=0;
    while(pos1<pos2 && (cur1<n &&cur2<n)){
        if((a[cur1]-pos1)*v2 <=(pos2-b[cur2])*v1){
            if((pos2-pos1)*v1<=(a[cur1]-pos1)*(v1+v2)){
                t+=(pos2-pos1)/(v1+v2);
                pos1=pos2;

            }
            else{
            double temp=(a[cur1]-pos1)/v1;
            pos2=pos2-v2*temp;
            t+=temp;
            pos1=a[cur1];
            v1++;
            cur1++;}
        }
        else{
            if((pos2-pos1)*v2<=(pos2-b[cur2])*(v1+v2)){
                t+=(pos2-pos1)/(v1+v2);
                pos1=pos2;

            }
            else{
            double temp=(pos2-b[cur2])/v2;
            pos1=pos1+v1*temp;
            t+=temp;
            pos2=b[cur2];
            v2++;
            cur2++;}

        }
        
        
    }
    t+=(pos2-pos1)/(v1+v2);
    cout<<setprecision(12)<<fixed<<t<<endl;




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