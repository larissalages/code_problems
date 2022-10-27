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
    char c;
    string s;
    cin>>n>>c>>s;
    if(c=='g'){
        cout<<"0"<<endl;
        return;
    }
    auto it=find(all(s),'g');
    ll index=it-s.begin();
    ll ma=-1;
    ll index1=-1;
    fl(i,0,n){
        if(s[i]==c&&index1==-1)
            index1=i;
        else if(s[i]=='g'&&index1!=-1){
            ma=max(ma,i-index1);
            index1=-1;
        }
    }
    if(index1!=-1)
        ma=max(ma,n-index1+index);
    cout<<ma<<endl;
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