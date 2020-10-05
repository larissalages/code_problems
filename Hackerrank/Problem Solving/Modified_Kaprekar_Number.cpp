#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
long long int p,q,i,j,k,m,s,flag=0; 
cin>>p>>q;
for( i=p;i<=q;i++)
{ 
int l=0; 
j=i;
while(j>0)
{ 
  l++;
  j=j/10;
}
k=i*i;
m = pow(10,l);
s = k/m + k%m;
if(s == i)
{
    cout<<i<<" ";
    flag ++;
}
}
if (flag == 0)
{
    cout<<"INVALID RANGE";
}
return 0;
}
