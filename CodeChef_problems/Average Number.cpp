#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n, k, v, a1, i;
        ll sum=0;
        cin>>n>>k>>v;
        vector<ll> a;
        for(i=0;i<n;i++)
        {
            cin>>a1;
            a.push_back(a1);
        }
        for(i=0;i<n;i++)
        {
            sum+=a[i];
        }
        if((v*(n+k)-sum)%k==0 && v*(n+k)-sum>0)
        cout<<(v*(n+k)-sum)/k<<endl;
        else
            cout<<"-1"<<endl;
    }

}

