// Author:Nishtha
#include <bits/stdc++.h> 
using namespace std; 
  
#define fi(i,a,n) for (int i=a; i < n; i++) 
#define ll long long

struct Node{
  int data;
  struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

// output the linked list
void Display(struct Node *p){
  while(p!=NULL){
    cout<<p->data<<" ";
    p=p->next;
  }
}

// creatingg first linked list using array a
void create(int a[], int n){
  int i;
  struct Node *t,*last;
  first= new Node;
  first->data=a[0];
  first->next=NULL;
  last=first;

  fi(i,1,n){
    t=new Node;
    t->data=a[i];
    t->next=NULL;
    last->next=t;
    last=t;
  }
}

// creating 2nd linked list using array b for merging
void create2(int a[], int n){
  struct Node *t,*last;
  second= new Node;
  second->data=a[0];
  second->next=NULL;
  last=second;

  fi(i,1,n){
    t=new Node;
    t->data=a[i];
    t->next=NULL;
    last->next=t;
    last=t;
  }
}

// inserting new element in sorted linked list
void sortedInsert(struct Node *p,ll x){
  struct Node *t,*q=NULL;
  t=new Node;
  t->data=x;
  t->next=NULL;

  if(first==NULL){
    first=t;
  }
  else{
    while (p && p->data<x)
    {
      q=p;
      p=p->next;
    }
    if(p==first){
      t->next=first;
      first=t;
    }else{
      t->next=q->next;
      q->next=t;
    }
    
  }
}

// counting the legth of linked list
int count(struct Node *p){
  int l=0;
  while(p){
    l++;
    p=p->next;
  }
  return l;
}

// summing up the elements in linked list
int sum(struct Node *p){
  int sum=0;
  while(p){
    sum+=p->data;
    p=p->next;
  }
  return sum;
}

// finding max
int Max(struct Node *p){
  int max=INT_MIN;
  while(p){
    if(p->data>max){
      max=p->data;
    }
    p=p->next;
  }
  return max;
}

// Linear search
struct Node *Search(struct Node *p,int key){
  struct Node *q;
  while(p){
    if(key==p->data){
      q->next=p->next;
      p->next=first;
      first=p;
      return p;
    }
    q=p;
    p=p->next;
  }
  return NULL;
}

void insert(struct Node *p, int index, int x){
  struct Node *t;
  int i;
  if(index<0 || index>count(p)){
    return;
  }
  t=new Node;
  t->data=x;
  if(index==0){
    t->next=first;
    first=t;
  }else{
    for(i=0;i<index;i++){
      p=p->next;
    }
    t->next=p->next;
    p->next=t;
  }
}

void Reverse2(struct Node *p){
  struct Node *q=NULL,*r=NULL;
  while(p!=NULL){
    r=q;
    q=p;
    p=p->next;
    q->next=r;
  }
  first=q;
}

// Concating 2 linked lists
void Concat(struct Node *p, struct Node *q){
  third=p;
  while(p->next!=NULL){
    p=p->next;
  }
  p->next=q;
}

// merging 2 linked lists
void Merge(struct Node *p, struct Node *q){
  struct Node *last;
  if(p->data < q->data){
    third=last=p;
    p=p->next;
    third->next=NULL;
  }
  else{
    third=last=q;
    q=q->next;
    third->next=NULL;
  }
  while(p && q){
    if(p->data <q->data){
      last->next=p;
      last=p;
      p=p->next;
      last->next=NULL;
    }
    else{
      last->next=q;
      last=q;
      q=q->next;
      last->next=NULL;
    }
  }
  if(p) last->next=p;
  if(q) last->next=q;
}

// to check whether a linked list is loop or not
int isLoop(struct Node *first){
  struct Node *p,*q;
  p=q=first;
  do
  {
    p=p->next;
    q=q->next;
    q=q?q->next:q;
  } while (p && q && p!=q);
  if(p==q)
  return 1;
  else return 0;
}

int main() 
{  
  int a[]={10,20,30,40,50};  
  create(a,5);
  // int b[]={5,15,25,35,45};
  // create2(b,5);
  // Merge(first,second);
  // Display(third);
  // sortedInsert(first,15);
  // Display(first);

  // Loop bnane k liye
  struct Node *t1,*t2;
  t1=first->next->next;
  t2=first->next->next->next->next;
  t2->next=t1;
  cout<<isLoop(first);
  return 0; 
} 
