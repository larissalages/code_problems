#include<iostream>
#include<vector>

using namespace std;

int main(){
  vector<int> v;
  vector<int> v2;
  v.assign(1000001,0);
  long long int dig=1,i=1,j,digit;
  while(i<=1000000){
    //cout<<dig<<endl;
    digit=dig;
    v2.clear();
    while(digit!=0){
      v2.push_back(digit%10);
      digit/=10;
    }
   for(j=v2.size()-1;j>=0;j--){
     v[i]=v2[j];
  //   cout<<v[i]<<endl;
     i++;
   }
   dig++;
  }
  cout<<v[1]*v[10]*v[100]*v[1000]*v[10000]*v[100000]*v[1000000];
}