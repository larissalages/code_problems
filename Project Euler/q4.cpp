#include <algorithm>
#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

bool check(ll a)
{
    ll temp = a;
    ll count = 0;
    while(temp != 0)
    {
        temp /= 10;
        count += 1;
    }
    ll arr[count],b = 0;
    while(a != 0)
    {
        arr[b++] = a%10;
        a /= 10;
    }
    ll flag = 0;
    for(ll i=0;i<count/2;i++)
    {
        if(arr[i] != arr[count-i-1])
            {
                flag = 1;
                break;
            }
    }
    if(flag)
        return false;
    else
        return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set <ll> s;
    for(ll i=100;i<1000;i++)
    {
        for(ll j=100;j<1000;j++)
        {
            ll prod = i*j;
            if(check(prod))
                s.insert(prod);
        }
    }
    ll sizea = s.size();
    ll ae[sizea],k = 0;
    for(auto it : s)
        ae[k++] = it;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll index = lower_bound(ae,ae+sizea,n) - ae;
        cout<<ae[index-1]<<"\n";
    }
    return 0;
}
