#include <iostream>
#include<bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        long long int f1 = 1,f2 = 2,f = 0, sum = 0;
        while(f1 < n)
        {
            if(f1 % 2 == 0)
            {
                sum += f1;
            }
            f = f1 + f2;
            f1 = f2;
            f2 = f;
        }
        cout << sum << endl;
    }   return 0;
}