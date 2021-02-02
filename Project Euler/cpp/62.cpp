#include<vector>
#include<iostream>
#include<stdlib.h>
#include<map>

using namespace std;

unsigned long long int fingerprint(vector<unsigned long long int> digit){
  unsigned long long int i,k,dig,shift,fp=0;
  for(k=0;k<digit.size();k++){
    shift=1;
    dig=digit[k];
    for(i=0;i<dig;i++) shift*=10;
    fp+=shift;
  }
  return fp;
}

int main(){
   vector<unsigned long long int> cube,temp2,fp2;
   map<unsigned long long int, vector<unsigned long long int> > mp;
  map<unsigned long long int, int > mp2;
  long long int temp,fp,j,k,carry;
  int i;
  for(i=10;i<=10000;i++){
    temp=i;
    cube.clear();
    while(temp!=0){
        cube.push_back(temp%10);
        temp/=10;
    }
    for(j=1;j<=2;j++){
        temp2.clear();
        carry=0;
        for(k=0;k<cube.size();k++){
            temp=cube[k]*i+carry;
            temp2.push_back(temp%10);
            carry=temp/10;
        }
        while(carry!=0){
             temp2.push_back(carry%10);
             carry/=10;
        }
    cube=temp2;
    }
    fp=fingerprint(cube);
    if(mp.find(fp)!=mp.end()){
      mp2[fp]++;
      if(mp2[fp]==5){
        for(j=mp[fp].size()-1;j>=0;j--) 
           cout<<mp[fp][j];
        exit(0);
      }
    }else{
       mp[fp]=cube;
       mp2[fp]=1;
    }
  }
}
