#include<iostream>
using namespace std;

int main()
{
    int i,j,k,n;
    cin>>n;
   
    for (i = 0; i <= n/2 ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            if((j >= (n/2)-i) && (j <= (n/2)+i))
                cout<<"  ";
            else
                cout<<"* ";
        }
        cout<<endl;
    }

    for (i = 0; i < n/2 ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            if((j <= i) || (j >= (n-i-1)))
                cout<<"* ";
            else
                cout<<"  ";
        }
        cout<<endl;
    }
    

    return 0;
}