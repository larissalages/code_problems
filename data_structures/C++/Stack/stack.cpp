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
#define max 1000
ll a[max],top=-1;

bool empty(){
  if(top==-1)
    return true;
  else return false;
}

void push(ll x){
  if(top==max){
    cout<<"Overflow"<<"\n";
  }
  top++;
  a[top]=x;
}

ll pop(){
  if(empty())
    return 0;
  else{
    top--;
    return a[top+1];
  }
}

int main() {
  ll queries;
  cout<<"Enter no. of queries"<<"\n";
  cin>>queries;
  fi(i,0,queries){
    string s;
    cin>>s;
    if(s=="push"){
      ll x;
      cin>>x;
      push(x);
    }else if(s=="pop"){
      cout<<pop()<<"\n";
    }else{
      cout<<"Invalid String"<<"\n";
    }
  }
	return 0; 
} 