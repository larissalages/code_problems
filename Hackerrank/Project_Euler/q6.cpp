#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long int t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        unsigned long int n,sum1=0,sum2=0;
        cin>>n;
        sum1=(n*(n+1))/2;
        sum2=(n*(n+1)*(2*n+1))/6;
        cout<<(sum1*sum1)-sum2<<endl;
    }
return 0;
}