#include<iostream>
using namespace std;

int main()
{
    int n,i,j,k;
    cin>>n;

    for(i=0 ; i<n ; i++)
    {
        k=i;
        while (k) 
        {
            cout<<"  ";
            k--;
        }
        for(j=0 ; j<n-i ; j++)
        {
            cout<<"* ";                        
        }
        cout<<endl;
    }
    
    return 0;
}