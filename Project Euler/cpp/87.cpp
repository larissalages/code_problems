#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

int main(){
  vector<int> v;
  v.assign(7100,0);
  map<long long int,long long int> mp;
  unsigned long long int i,j,k, max=50000000,temp,a1,a2,a3;
  for(i=2;i<7100;i++){
    if(v[i]==0 || v[i]==1){
      for(j=i;j<7100;j+=i) v[j]++;
    }
  }
  for(i=2;i<=7100;i++){
    if(v[i]==1){
      for(j=2;j<=370;j++){
        if(v[j]==1){
          if((i*i+j*j*j)>max) break;
            for(k=2;k<=85;k++){
              if(v[k]==1){
                a1=i*i;
                a2=(unsigned long long int)j*j*j;
                a3=(unsigned long long int)k*k*k*k;
                temp=a1+a2+a3;
                if(temp>=max) break;
                 mp[temp]=i;
              }
            }
        }
      }
    }
  }
  cout<<mp.size();
}