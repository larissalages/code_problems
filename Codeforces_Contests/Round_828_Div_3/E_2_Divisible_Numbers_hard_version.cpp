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
    vector<ll>pa,pd;
    for(ll i=1; i<=sqrt(a); i++){
        if (a%i == 0)
        {
            pa.pb(i);
        }
    }
    for(ll i=1; i<=sqrt(b); i++){
        if (b%i == 0)
        {
            pd.pb(i);
        }
    }
    fl(i,0,pa.size()){
        fl(j,0,pd.size()){
            ll m1=a,m2=b;
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
            m1=pa[i]*pd[j],m2=(a/pa[i])*(b/pd[j]);
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
            m1=pa[i]*(b/pd[j]),m2=(a/pa[i])*pd[j];
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