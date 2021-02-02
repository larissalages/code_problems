#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  vector<int> d,v;
  vector<int>::iterator p1,p2;
  int temp,digit,i,pos1,pos2;
  while(true){
    cin>>digit;
    d.clear();
    while(digit!=0){
      d.push_back(digit%10);
      digit/=10;
    }
    for(i=d.size()-1;i>=0;i--){
      if(find(v.begin(),v.end(),d[i])==v.end())    v.push_back(d[i]);
    }
    for(i=d.size()-1;i>0;i--){
      p1=find(v.begin(),v.end(),d[i]);
      p2=find(v.begin(),v.end(),d[i-1]);
      pos1=p1-v.begin();
      pos2=p2-v.begin();
      if(pos2<pos1){
         temp=v[pos1];
         v[pos1]=v[pos2];
         v[pos2]=temp;
      }
    }
    for(i=0;i<v.size();i++) cout<<v[i];
    cout<<endl;
  }
}