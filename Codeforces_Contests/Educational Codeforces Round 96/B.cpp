#include<bits/stdc++.h>
#define int long long
#define pb emplace_back
#define mp make_pair
#define mt make_tuple
#define all(v) v.begin(),v.end()
#define rep(i,start,lim) for(long long (i)=(start);i<(lim);i++)
#define revrep(i,n) for(long long i=n-1;i>=0;i--)
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define osit ostream_iterator<int> output (cout," ")
#define endl '\n'
#define f first
#define s second
#define PI 3.141592653589793
#define MOD 1000000007
#define set0(x) memset(x,0,sizeof(x))
#define set1(x) memset(x,1,sizeof(x))
using namespace std;
typedef vector<int> vi;
typedef list<int> li;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;
template<typename T> T gcd(T a,T b){if(a==0) return b; return gcd(b%a,a);}
template<typename P> P dectobin(P a){if(a==0)return 0; else return(a%2 + 10*dectobin(a/2));}
template<typename Y> Y bintodec(Y a){int ans=0,b=1,t=a; while (t){int ld=t%10; t/=10;ans+=ld* b;b=b*2;} return ans; }
template<typename H> H modExp(H x, H n){ int r=1; while(n>0){if(n%2==1){r=(r*x)%MOD;}x=(x*x)%MOD;n/=2;}return r;}
template<typename T> T isPowerOfTwo(T x){return x && (!(x & (x - 1)));}	
template<typename T> T lcm(T a,T b) {return a*b/gcd(a,b);}
//template<typename T> T extendedEuclid(T A,T B){if(B==0){d=A; x=1;y=0;}else{ extendedEuclid(B,A%B);int temp=x; x=y; y=temp-(A
//B)*y;}}
int32_t main(){
	boost;osit;
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int arr[n],sum=0;
		rep(i,0,n) cin>>arr[i];
		sort(arr,arr+n);
		for(int i=n-1;i>=(n-k-1);i--) sum+=arr[i];
		cout<<sum<<endl;
	}
	return 0;
}
