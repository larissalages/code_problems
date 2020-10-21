#include <bits/stdc++.h>
using namespace std;
int main()
{
   long long n;
   cin>>n;
   vector<long long> fact(21);
   fact[0]=1;
   long long pro=1;
   for(long long i=1;i<=20;i++)
   {
       pro*=i;
       fact[i]=pro;
   }
   long long combinations=((fact[n]/(fact[n/2]*fact[n/2]))*fact[n/2-1]*fact[n/2-1])/2;
   cout<<combinations;
   return 0;
}