#include"bits/stdc++.h"
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define read(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
const int N=1e5 + 2;
void func1(){
    int a,b,c;cin>>a>>b>>c;
    int mx = max(a,b);
    int mn = min(a,b);
    int diff = mx - mn;
    int total = 2*(mx-mn);
    if(((2*mn)-mx >= 1)||(mx-mn == 1)){
        cout<<-1;
        return;
    }
    if(c>diff){
        if(c-diff > diff){
            cout<<-1;
        }
        else{
            cout<<(c-diff);
        }
    }
    else{
        cout<<(c+diff);
    }
}
int main(){
    int t;
    t=1;
    cin>>t; //for single test case remove it
    while(t--){
        func1();
        if(t!=0)
        cout<<endl;
    }
    return 0;
}