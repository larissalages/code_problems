/*
Author - Silent Knight
Institution - BIT Mesra
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

//UPSOLVED

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[n];
        ll b[n];
        for(ll i=0;i<n;i++)
            cin>>a[i]>>b[i];
        ll bull = 0, mini = 1e18,temp,des;
        for(ll i=0;i<n;i++)
        {
            temp = (i+1)%n;
            des = min(a[temp],b[i]);
            bull += (a[temp] - des);
            mini = min(mini,des);
        }
        bull += mini;
        cout<<bull<<"\n";
    }
    return 0;   
}