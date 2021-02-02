#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,size = 1e6+1e5,temp,d,ans = 0,sum = 0;
    cin>>n;
    for(ll i=2;i<=size;i++)
    {
        temp = i;
        sum = 0;
        while(temp != 0)
        {
            d = temp%10;
            sum += (pow(d,n));
            temp /= 10;
        }
        if(sum == i)
            ans += i;
    }
    cout<<ans<<"\n";
    return 0;
}
