#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<vector>

using namespace std;

int main(){
  int flag;
  vector<unsigned long long int> v;
  v.assign(1000000,0);
  unsigned long long int i,j,n2;
  for(i=2;i<1000000;i++){
    if(v[i]==0 || v[i]==1){
      for(j=i;j<1000000;j+=i) v[j]++;
    }
  }
  double n;
  i=9;
  while(true){
   if(v[i]==1){
        i+=2;
        continue;
    }
    flag=0;
    for(j=1;2*j*j<i;j++){
      if(v[i-2*j*j]==1) flag=1;
    }
    if(flag==0) cout<<i<<endl;
    i+=2;
  }
}