#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,q,j,w;
    cin>>n>>k>>q;
    int a[n],i,b[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        b[(i+k)%n]=a[i];
    }
    for(i=0;i<q;i++)
    {
        int m;
        cin>>m;
        cout<<b[m]<<endl;
    }
    return 0;
}
