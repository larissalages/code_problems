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
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll num=a*b;
    vector<ll>prime;
    for(ll i=1; i<=sqrt(num); i++){
        if (num%i == 0)
        {
            prime.pb(i);
        }
    }


    fl(i,0,prime.size()){
        ll m1=prime[i],m2=num/m1;
        if((c/m1-a/m1)&&(d/m2-b/m2)){
            ll x=c-(c%m1),y=d-(d%m2);
            cout<<x<<" "<<y<<endl;
            return;
        }
        if((c/m2-a/m2)&&(d/m1-b/m1)){
            ll x=c-(c%m2),y=d-(d%m1);
            cout<<x<<" "<<y<<endl;
            return;
        }
    }
    cout<<"-1 -1"<<endl;
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