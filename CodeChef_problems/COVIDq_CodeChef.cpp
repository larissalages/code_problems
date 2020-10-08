#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
	    int N;
	    int flag=0;
	    cin>>N;
	    int arr[N];
	    for(int i=0;i<N;i++)
	    {
	        cin>>arr[i];
	        
	    }
	    for(int j=0;j<N;j++)
	    {
	        if(arr[j]==1)
	        {   
	            for(int k=j+1;k<=j+5 && k<N;k++)
	            {
	                if(arr[k]==1)
	                {
	                   
	                    flag=1;
	                    break;
	                }
	               
	            }
	        }
	        if(flag==1)
	        break;
	    }
	    if(flag==0)
	    cout<<"YES"<<endl;
	    else
	     cout<<"NO"<<endl;
	}
	return 0;
}

