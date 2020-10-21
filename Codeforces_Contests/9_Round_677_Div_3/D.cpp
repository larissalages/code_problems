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
       int found=0;
       long long compare=v[0],ind1=0,ind2=-1;;
       for(long long i=1;i<n;i++)
       {
           if(compare!=v[i])
           {
               found=1;
               ind2=i;
               break;
           }
       }
       if(found==0)
       {
           cout<<"NO\n";
           continue;
       }
       cout<<"YES\n";
       cout<<ind1+1<<" "<<ind2+1<<"\n";
       for(long long i=1;i<n;i++)
       {
           if(v[i]!=v[ind1]&&i!=ind2)
            cout<<ind1+1<<" "<<i+1<<"\n";
           else if(v[i]!=v[ind2])
            cout<<ind2+1<<" "<<i+1<<"\n";
       }
   }
   return 0;
}