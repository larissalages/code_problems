#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int rp,lp,i,j,rows=100,cols,sum,x;
  vector<int> last,curr;
  cin>>x;
  last.push_back(x);
  for(i=1;i<rows;i++){
    cols=i+1;
    curr.clear();
    for(j=0;j<cols;j++){
      cin>>x;
      lp=0;   //left parent
      if(j>0) lp=last[j-1];
      rp=0;   //right parent
      if(j<last.size()) rp=last[j];
      sum=x+max(lp,rp);
      curr.push_back(sum);
    }
    last=curr;
  }
  cout<<*max_element(last.begin(),last.end());
}