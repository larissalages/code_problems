#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll m = -1; 

        while (n % 2 == 0) 
        { 
            m = 2; 
            n /= 2; 
        } 
    
        for (ll i = 3; i <= sqrt(n); i += 2) { 
            while (n % i == 0) { 
                m = i; 
                n = n / i; 
            } 
        } 
        if (n > 2) 
            m = n; 
    
        cout<<m<<"\n";
    }
    return 0;
}
