#include <bits/stdc++.h>
using namespace std;
int main()
{
   long long t;
   cin>>t;
   while(t--)
   {
       long long n;
       cin>>n;
       vector<long long> v(n);
       for(long long i=0;i<n;i++)
        cin>>v[i];
       long long large=*max_element(v.begin(),v.end());
       long long ans=-2;
       for(long long i=0;i<n;i++)
       {
           if(v[i]==large)
           {
               if(i!=0 && v[i-1]<large || i!=(n-1) && v[i+1]<large)
                  ans=i;
           }
       }
       cout<<ans+1<<"\n";
   }
   return 0;
}