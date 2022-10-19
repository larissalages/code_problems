#include"bits/stdc++.h"
#include<cmath>
#include<string>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define read(arr,n) for(int i=0;i<n;i++) cin>>arr[i];
const int N=1e5 + 2;
void func1(){
    int n;cin>>n;
    int num=1;
    int i=1;
    while(i<n){
        num++;
        if((num%3 != 0)&&(num%10 != 3)){
            i++;
        }
        // else{
        //     num++;
        // }
    }
    cout<<num;
}
int main(){
    int t;
    t=1;   //for multiple testcases remove this part
    cin>>t; //for single test case remove it
    while(t--){
        func1();
        if(t!=0)
        cout<<endl;
    }
    return 0;
}