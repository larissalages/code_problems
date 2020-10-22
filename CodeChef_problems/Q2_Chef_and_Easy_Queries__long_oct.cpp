/*
contest link : https://www.codechef.com/OCT20B
question link : https://www.codechef.com/OCT20B/problems/CHEFEZQ
*/

#include<bits/stdc++.h> 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
using namespace std; 

int main()
		{
		fast;
		int t;
        cin>>t;
		while(t--)
		{
			ll n,k;
            cin>>n>>k;
			
			ll a[n];
			ll sum=0;
			for(ll i=0;i<n;i++)
			{
				cin>>a[i];
				sum+=a[i];
			}
			ll count=0,flag=0;
			for(ll i=0;i<n-1;i++)
			{
				if(a[i]>=k)
				{
					a[i+1]+=a[i]-k;
					count++;
				}
				else
				{
					flag=1;
					count++;
					break;
				}
			}
			if(flag==1)
			{
				cout<<count<<"\n";
			}
			else
			{
				
				ll ans=count+a[n-1]/k+1;
				cout<<ans<<"\n";
			}
		}
					
	
	}
