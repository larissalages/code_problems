#include<iostream>
using namespace std;

int main()
{
    int n,i,j,k;
    cin>>n;

    for(i=1 ; i<=n ; i++)
    {
        // k=n-i;
        // while (k) 
        // {
        //     cout<<"  ";
        //     k--;
        // }
        // for(j=1 ; j<=i ; j++)
        // {
        //     cout<<"*   ";                        
        // }
        // cout<<endl;
        k=0;
        while (k != (n-i))
        {
            cout<<" ";
            k++;
        }
        for ( j = 1; j <= (2*i)-1 ; j++)
        {
            if((j%2)==0)
                cout<<" ";
            else
                cout<<"*";
        }
        cout<<endl;
        
    }
    
    return 0;
}