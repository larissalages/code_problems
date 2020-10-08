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
ll a[max],head=-1,tail=-1;

bool empty(){
  if(head==tail)
    return true;
  else return false;
}

bool full(){
  if(head==tail+1)
    return true;
  else return false;
}

void enqueue(ll x){
  if(full()){
    cout<<"Overflow"<<endl;
  }
  else{
    a[tail]=x;
    if(tail==max-1){
      tail=0;
    }
    else tail++;
  }
}

ll dequeue(){
  if(empty()){
    return 0;
  }else{
    ll x=a[head];
    if(a[head]==max-1)
      head=0;
    else head++;
    return x;
  }
}

int main() {
  ll queries;
  cout<<"Enter no. of queries"<<"\n";
  cin>>queries;
  fi(i,0,queries){
    string s;
    cin>>s;
    if(s=="enqueue"){
      ll x;
      cin>>x;
      enqueue(x);
    }else if(s=="dequeue"){
      cout<<dequeue()<<"\n";
    }else{
      cout<<"Invalid String"<<"\n";
    }
  }
	return 0; 
} 