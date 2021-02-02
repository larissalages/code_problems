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
        ll s = 0;
        n -= 1;
        ll three = n/3;
        ll five = n/5;
        ll fifteen = n/15;
        three = (three*(three+1))/2;
        five = (five*(five + 1))/2;
        fifteen = (fifteen*(fifteen+1))/2;
        s = s + (three*3) + (five*5) - (fifteen*15);

        cout<<s<<"\n";
    }
    return 0;
}
