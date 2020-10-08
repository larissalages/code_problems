#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;// number of test cases
	while(t--)
	{
		int s,p1,p2,k;
		cin>>p1>>p2>>k;
		s=int((p1+p2)/k);   //no. of times serves will change
		if(s%2==0)   //check if that number is even or odd
			cout<<"CHEF"<<endl;
		else
			cout<<"COOK"<<endl;
	}

}

