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
        ll n,k;
        cin>>n>>k;
        ll a[n],b[n],c[n];
        ll max=INT_MIN;
        ll min=INT_MAX;
        fi(i,0,n){
            cin>>a[i];
            if(a[i]>max){
                max=a[i];
            }
            if(a[i]<min){
                min=a[i];
            }
        }
        fi(i,0,n){
            b[i]=max-a[i];
            c[i]=(max-min)-b[i];
        }
        if(n==1){
            cout<<0;
        }else if(k%2==0){
            fi(i,0,n){
                cout<<c[i]<<" ";
            }
        }else{
            fi(i,0,n){
                cout<<b[i]<<" ";
            }
        }
        cout<<"\n";

        
    }
	return 0; 
} 