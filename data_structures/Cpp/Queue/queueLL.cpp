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

struct Node{
  int data;
  struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
  struct Node *t;
  t=new Node;
  if(t==NULL)
    cout<<"Queue is full"<<endl;
  else{
    t->data=x;
    t->next=NULL;
    if(front==NULL){
      front=rear=t;
    }else{
      rear->next=t;
      rear=t;
    }
  }
}

int dequeue(){
  int x=-1;
  struct Node *t;
  if(front==NULL)
    cout<<"queue is empty"<<endl;
  else{
    x=front->data;
    t=front;
    front=front->next;
    delete t;
  }
  return x;
}

void Display(){
  struct Node *p;
  while(p){
    cout<<p->data<<" ";
    p=p->next;
  }
  cout<<"\n";
}

int main() {
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);
  Display();
  cout<<dequeue()<<endl;
	return 0; 
} 