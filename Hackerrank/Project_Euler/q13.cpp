#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    string s[t];
    for(ll i=0;i<t;i++)
        cin>>s[i];
    ll res = 0;
    vector <ll> ans;
    for(ll i=49;i>=0;i--)
    {
        for(ll j=0;j<t;j++)
            res += (s[j][i] - '0');
        ans.push_back(res%10);
        res /= 10;
    }
    while(res != 0)
    {
        ans.push_back(res%10);
        res /= 10;
    }
    reverse(ans.begin(),ans.end());
    ll h = 0;
    for(auto it : ans)
    {
        h += 1;
        cout<<it;
        if(h == 10)
            break;
    }
    return 0;
}
