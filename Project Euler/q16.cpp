#include<bits/stdc++.h>

#define pb push_back
#define bigint int64_t

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    /////////////////////////////////////////////////////////////////sieve
    ll size = 1e5;
    bool isprime[size];
    for(ll i=0;i<size;i++)
        isprime[i] = true;
    isprime[0] = isprime[1] = false;
    for(ll i=0;i<size;i++)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<size;j+=i)
            {
                isprime[j] = false;
            }
        }
    }
    //////////////////////////////////////////////////////////////////////
    vector <ll> v[10001];
    v[1].push_back(2);
    for(ll i=2;i<10001;i++)
    {
        ll carry = 0,temp;
        for(auto it : v[i-1])
        {
            temp = it*2;
            temp += carry;
            v[i].push_back(temp%10);
            carry = temp/10;
        }
        while(carry != 0)
            {
                v[i].push_back(carry%10);
                carry /= 10;
            }
    }

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        
        ll sum = 0;
        for(auto it : v[n])
            sum += it;
        cout<<sum<<"\n";
    }
    //////////////////////////////////////////////////////////////////////
    return 0;
}
