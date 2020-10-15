#include<iostream>
using namespace std;

int main()
{
    int n,i,j,k=1;
    cin>>n;

    for (i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=i ; j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;        
    }
    i=0;j=0;
    for(i=n-1 ; i>=1 ; i--)
    {
        for(j=1 ; j<=i ; j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    
   
    return 0;
}