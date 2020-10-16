#include <bits/stdc++.h>
#include<math.h>
using namespace std;
#define MOD 1000000007
#define ll long long int
#define fi(i,a,n) for(ll i=a;i<n;i++)
#define fd(i,a,n) for(ll i=a;i>=n;i--)
#define pb push_back
#define fv(i,a) for(auto i:a) 
#define vi vector<int>

void calculateSpan(ll price[], ll n, ll values[]){
  stack<ll>s;
  // pehle wale k lie
  values[0]=1;
  s.push(0);

  fi(i,1,n){
    // agar new wala pehle se bada h to pop krte jao jab tk ya to usse chhota na mile ya bucket khali na ho jae
    while(price[i]>price[s.top()]){
      s.pop();
      if(s.empty())
        break;
    }
    if(!s.empty()){
      values[i]=i-s.top();
    }else{
      values[i]=i+1;
    }
    s.push(i);
  }
}

int main() { 
  ll n;
  cin>>n;
  ll price[n];
  fi(i,0,n){
    cin>>price[i];
  }
  ll values[n];
  calculateSpan(price,n,values);
  fi(i,0,n)
  cout<<values[i]<<" ";
	return 0; 
} 