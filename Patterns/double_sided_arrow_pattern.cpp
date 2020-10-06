#include<iostream>
using namespace std;
int main() 
{
	int n,k,l;
	cin>>n;
	int m=n/2;
	int a=n;
	if(n%2 != 0)
	{
	    for(int i=1; i<=((n/2) + 1);i++)
	    {
	        k=i;
	        
	        //outer left space
	        
	        for(int j=n/2;j>=i;j--)
	        {
	            cout<<"    ";
	        }
	        
	        //no.s
	        
	        for(int j=1;j<=i;j++)
	        {
	           cout<<k<<" ";
	           k--;
	        }
	        
	        //inner space
	        
	        for(int j=1;j<i;j++)
	        {
	            cout<<"  ";
	        }
	        for(int j = 2;j<i;j++)
	        {
	            cout<<"  ";
	        }
	 
	        //riht side no.s
	        if(i != 1)
	        {
	        l = 1;
	        for(int j=0;j<i;j++)
	        {
	            cout<<l<<" ";
	            l++;
	        }
	        }
	        
	        cout<<endl;
	    }
	    //lower part
	    for(int i=1;i<=n/2;i++)
	    {
	        int x=1;
	        //lower left corner space
	        for(int j=0;j<i;j++)
	        {
	            cout<<"    ";
	        }
	        
	        //numbers
	        for(int j=m;j>0;j--)
	        {
	            if(j!=1)
	             {cout<<j<<" ";}
	            else
	            {cout<<j;}
	        }
	        m--;
	        //inner space 
	        
	        for(int j=1;j<=a;j++)
	        {
	            if(i!=n/2)
	            {cout<<" ";}
	        }
	        a -= 2;
	        
	        //numbers
	        
	        for(int j=n/2 + 1;j>i;j--)
	        {
	            if(i!=n/2)
	            {
	            cout<<x<<" ";
	            x++;
	            }
	        }
	
	        cout<<endl;
	    }
	    
	}


	return 0;
}