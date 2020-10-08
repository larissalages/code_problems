// nb_9960
#include <bits/stdc++.h>
#include<math.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
#define fi(i,a,n) for(ll i=a;i<n;i++)
#define fd(i,a,n) for(ll i=a;i>=n;i--)
#define pb push_back
#define fv(i,a) for(auto i:a) 
#define vi vector<int>

int main() { 
    ll t=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n],diff[n];
        fi(i,0,n){
            cin>>a[i];
        }
        fi(i,0,n-1){
            diff[i]=a[i]-a[i+1];
        }
        ll ans=0;
        fi(i,0,n-1){
            if(diff[i]>0){
                ans+=diff[i];
            }
        }
        cout<<ans<<endl;
    }
	return 0; 
} 