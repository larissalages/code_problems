#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    vector<int> v;
    long long int i,j,a,b,n,max=0,ans=0;
    v.assign(1000000,0);
    for(i=2;i<1000000;i++){
      if(v[i]==0 || v[i]==1){
        for(j=i;j<1000000;j+=i){
            v[j]++;
        }
      }
    }
    for(a=-1000;a<1000;a++){
      for(b=1;b<=1000;b++){
       if(v[b]!=1) continue;
        n=0;
       while(v[abs(n*n+a*n+b)]==1) n++;
        if(n+1>max){
            max=n+1;
            ans=a*b;
        }
      }
    }
   cout<<ans;
}