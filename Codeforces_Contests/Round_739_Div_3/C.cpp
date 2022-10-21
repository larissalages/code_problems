#include"bits/stdc++.h"
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define read(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
const int N=1e5 + 2;
void func1(){
    int n;cin>>n;
    int num = 1;
    while(num*num < n){
        num++;
    }
    // num = num*num;
    if(num*num == n){
        cout<<num<<" "<<1;
        return;
    }
    int sq = num*num;
    if(n > sq-num){
        cout<<num<<" "<<1+(sq-n);
    }
    else if(n >= sq-num-num+2){
        cout<<num-(sq-num+1-n)<<" "<<num;
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