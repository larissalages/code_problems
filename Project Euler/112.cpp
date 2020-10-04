#include<iostream>
#include<stdlib.h>

using namespace std;

bool isbouncy(long long int digit){
  int flag,prev,curr;
    prev=digit%10;
    digit/=10;
  while(digit!=0){
     curr=digit%10;
     digit/=10;
     if(curr<prev){
        if(flag==1) return true;
       flag=0;
    }
    else if(curr>prev){
        if(flag==0) return true;
        flag=1;
    }
    prev=curr;
  }
   return false;
}

int main(){
  long long int digit=100,count=0;
  while(true){
    if(isbouncy(digit)) count++;
    if(((count*100)/digit)>=99){
        cout<<digit;
        exit(0);
    }
    digit++;
  }
}