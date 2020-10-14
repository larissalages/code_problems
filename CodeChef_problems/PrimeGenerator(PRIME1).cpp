#include <bits/stdc++.h> 
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef unsigned long long int unt;
using namespace std; 

bool Prime(unt n){

    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 

    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (unt i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 

void printPrime(unt a,unt n){ 
    for (unt i = a; i <= n; i++){ 
        if(Prime(i)) 
            cout <<i<<'\n'; 
    } 
} 

int main(){
	fast;
	unt t;
	cin>>t;
	while(t--){
	int a,n;
	cin>>a>>n;
    printPrime(a,n); 
	}
} 
