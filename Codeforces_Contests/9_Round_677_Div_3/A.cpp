#include <bits/stdc++.h>
using namespace std;
int main()
{
   long long t;
   cin>>t;
   while(t--)
   {
       long long x;
       cin>>x;
       int nod=0;
       long long cx=x,start=0;;
       while(cx>0)
       {
           if(cx>=1&&cx<=9)
              start=cx;
           nod++;
           cx/=10;
       }
       long long ans=(start-1)*10; 
       for(long long i=0;i<nod;i++)
       {
           ans+=(i+1);
       }
       cout<<ans<<"\n";
   }
   return 0;
}