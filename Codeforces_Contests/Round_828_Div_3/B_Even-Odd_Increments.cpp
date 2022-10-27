#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define ll long long
#define fl(x,y,n) for(ll x=y;x<n;x++)
#define rfl(x,y,n) for(ll x=y;x>=n;x--)
#define yesno  if(result) cout<<"YES"<<endl;else cout<<"NO"<<endl;
#define pb push_back
#define all(v) v.begin(),v.end()
#define rev(v) v.rbegin(),v.rend()

void sol(){
    ll n,q;
    cin>>n>>q;
    ll a[n],even=0,odd=0,even_sum=0,odd_sum=0;
    fl(i,0,n){
        cin>>a[i];
        if(a[i]%2)
            odd++,odd_sum+=a[i];
        else
            even++,even_sum+=a[i];
    }
    while(q--){
        ll b,x;
        cin>>b>>x;
        if(b==0){
            if(x%2==0){
                even_sum+=(even)*x;
            }
            else
                odd_sum+=(even*x),odd+=even,even=0;
        }
        else{
            if(x%2==0){
                odd_sum+=odd*x;
            }
            else
                even_sum+=odd*x,even+=odd,odd=0;
        }
        cout<<odd_sum+even_sum<<endl;
    }
}

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
        sol();
    return 0;
}