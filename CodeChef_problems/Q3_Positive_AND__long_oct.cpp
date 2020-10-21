/*
contest link : https://www.codechef.com/OCT20B
question link : https://www.codechef.com/OCT20B/problems/POSAND
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int n,flag=0;
    	scanf("%lld",&n);
    	long long int k=1;
    	while(pow(2,k)<n)
    	{
    	    k++;
    	    if(pow(2,k)==n)
    	        flag=1;
    	}
    	if(n==2)
    	printf("-1");
    	else if(flag==1)
    	    printf("-1\n");
    	else if(n==1)
    	    printf("1\n");
    	else if(n==3)
    	{
    	    printf("2 3 1\n");
    	}
    	else
    	{
    	    printf("2 3 1");
    	    long long int i=3;
    	    long long int m=2;
    	    while(m<=k&&i<n)
    	    {
    	        long long int a=pow(2,m)+1;
    	        long long int b=pow(2,m);
    	        printf(" %lld %lld",a,b);
    	        i=i+2;
    	        long long int j=2;
    	        while(1)
    	        {
    	            if(i==n)
    	                break;
    	            long long int d=pow(2,m)+j;
    	            printf(" %lld",d);
    	            j++;
    	            i++;
    	            if(d==(pow(2,m+1)-1))
    	            {
    	                m++;
    	                break;
    	            }
    	        }
    	    }
    	}   
    	printf("\n");
    }
	return 0;
}
