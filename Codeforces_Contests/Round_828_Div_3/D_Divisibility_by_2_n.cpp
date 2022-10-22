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
    ll n;
    cin>>n;
    vector<ll>vp;
    fl(i,1,n+1){
        ll j=i,add=0;
        while(j%2==0){
            add++;
            j/=2;
        }
        vp.pb(add);
    }
    sort(all(vp));
    reverse(all(vp));
    ll present=0;
    ll a[n];
    fl(i,0,n){
        cin>>a[i];
        ll j=a[i];
        while(j%2==0){
            present++;
            j/=2;
        }
    }
    ll req=n-present;
    ll ans=0;
    if(req<=0){
        cout<<"0"<<endl;
        return;
    }
    fl(i,0,vp.size()){
        if(vp[i]>=req){
            ans++,req=0;
            break;
        }
        else
            ans++,req-=vp[i];
    }
    if(req!=0)
        cout<<"-1"<<endl;
    else
        cout<<ans<<endl;
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