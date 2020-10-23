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
       long long noz=0;
       vector<long long> vindex;
       for(long long i=0;i<n;i++)
        {
            long long temp;
            cin>>temp;
            if(temp==1)
                vindex.push_back(i);
        }
       for(long long i=0;i<vindex.size()-1;i++)
       {
           if(vindex[i+1]-vindex[i]>1)
            noz+=(vindex[i+1]-vindex[i]-1);
       }
       cout<<noz<<"\n";
   }
   return 0;
}