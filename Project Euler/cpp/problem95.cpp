#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
  unsigned long long int i,divsum,maxcount=0,ans,j,res=0;
  map<unsigned long long int,unsigned long long int> mp;
  vector<unsigned long long int> v;
  v.assign(1000001,1);
  for(i=2;i<=500000;i++){
    for(j=i+i;j<=1000000;j+=i) v[j]+=i;
  }
   for(i=4;i<=1000000;i++){
   ans=i;
   divsum=i;
     mp.clear();
    while(mp.find(divsum)==mp.end()){
      mp[divsum]=divsum;
      if(divsum<i) ans=i;
      if(divsum>1000000) break;
      divsum=v[divsum];
    }
  if(divsum<=1000000 && divsum==i && mp.size()>maxcount){
        maxcount=mp.size();
       res=ans;
    }
   }
  cout<<res;
}