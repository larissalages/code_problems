/**************************************************************************
 *  $Id$
 *  File:	
 *
 *  Purpose:	
 *
 *  Author:	Sanchit Gupta (CS19B071)
 *
 *  Created:    
 *
 *  Last modified:  
 *
 *  Bugs:	
 *
 *  Change Log:	
 *
 * While(!(succeed==try());
 **************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main(){
  int t; cin>>t;
  while (t--)
   {
       int n,k;
  cin>>n,k;
  set<int>s;
  for (int i=0;i<n;i++){
    int a;
    cin>>a;
    s.insert(a);
  }
  if (s.size()>k){
    cout<<-1<<endl;
    return;
  }
  cout<<n*k<<endl;
  for (int i=0;i<N;i++){
    for (int b:s)
      cout<<b<<' ';
    for (int j=0;j<k-(int)s.size();j++)
      cout<<1<<' ';
  }
  cout<<endl;
   }
}