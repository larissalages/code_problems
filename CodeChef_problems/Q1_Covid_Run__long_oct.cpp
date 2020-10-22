/*
contest link : https://www.codechef.com/OCT20B
question link : https://www.codechef.com/OCT20B/problems/CVDRUN
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,x,y;
		cin>>n>>k>>x>>y;
		bool flag =false;
		int m, ini_x=x;
		
		while(true){
			m = (x+k)%n;
			if(x==y){
				flag = true;
				break;
			}
			if(m==y){
				flag = true;
				break;
			}
			if(m==ini_x){
				flag =false;
				break;
			}
			x = (x+k)%n;
			
			}
		if(flag){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	   
	}
}
