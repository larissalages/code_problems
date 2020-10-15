#include<iostream>
using namespace std;

int main()
{
    int n,i,j,k;
    cin>>n;

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
        {
            if((i==1) || (i==n) || (j==1) || (j==n))
                cout<<"* ";
            else
                cout<<"  ";           
        }
        cout<<endl;
    }

    // for(i=1 ; i<=n ; i++)
    // {
    //     if(i==1 || i==n)
    //     {
    //         for(j=1 ; j<=n ; j++)
    //         {
    //             cout<<"*";
    //         }
    //         cout<<endl;
    //     }
    //     else 
    //     {
    //         cout<<"*";
    //         for(k=1 ; k<=n-2 ; k++)
    //             cout<<" ";
    //         cout<<"*"<<endl;
    //     }
    // }  
    return 0;
}