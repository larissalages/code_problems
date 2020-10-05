#include<iostream>
#include<vector>

using namespace std;

int main(){
  int ans=0,num,den,rem,count,max=0;
  vector<int> v;
  for(den=2;den<1000;den++){
   num=1;
   rem=0;
   count=0;
   v.clear();
   v.assign(den,0);
   while(v[num]==0){
    v[num]=count;
    num=(num*10)%den;
    count++;
   }
   if(count-v[rem]>max){
     max=count-v[rem];
     ans=den;
   }
  }
  cout<<max;
}