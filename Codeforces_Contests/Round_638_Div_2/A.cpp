/**************************************************************************
 *  $Id$
 *  File:	
 *
 *  Purpose:	
 *
 *  Author:	Sanchit Gupta (CS19B071)
 *
 *  Created:    
 *
 *  Last modified:  
 *
 *  Bugs:	
 *
 *  Change Log:	
 *
 * While(!(succeed==try());
 **************************************************************************/
 #include<iostream>
 #include<bits/stdc++.h>
 
 using namespace std;
 
 int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
        long long int n;
        cin>>n;
        long long int sum1=0,sum2=0;
        long long int current=2,i=1;
        while(i<(n/2))
        {
            sum1=sum1+current;
            current=current*2;
            i++;
        }
        while(i<n)
        {
            sum2=sum2+current;
            current=current*2;
            i++;
        }
        sum1=sum1+current;
        cout<<abs(sum1-sum2)<<endl;
     }
 }