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
    map <ll,string> mp;
    mp[0] = "Zero";
    mp[1] = "One";
    mp[2] = "Two";
    mp[3] = "Three";
    mp[4] = "Four";
    mp[5] = "Five";
    mp[6] = "Six";
    mp[7] = "Seven";
    mp[8] = "Eight";
    mp[9] = "Nine";
    mp[10] = "Ten";
    mp[11] = "Eleven";
    mp[12] = "Twelve";
    mp[13] = "Thirteen";
    mp[14] = "Fourteen";
    mp[15] = "Fifteen";
    mp[16] = "Sixteen";
    mp[17] = "Seventeen";
    mp[18] = "Eighteen";
    mp[19] = "Nineteen";
    mp[20] = "Twenty";
    mp[30] = "Thirty";
    mp[40] = "Forty";
    mp[50] = "Fifty";
    mp[60] = "Sixty";
    mp[70] = "Seventy";
    mp[80] = "Eighty";
    mp[90] = "Ninety";
    mp[100] = "Hundred";
    mp[1000] = "Thousand";
    mp[1000000] = "Million";
    mp[1000000000] = "Billion";
    for(ll i=2;i<=9;i++)
    {
        for(ll j=1;j<=9;j++)
        {
            ll key = i*10 + j;
            mp[key] = mp[i*10] + " " + mp[j];
        }
    }
    ////////////////////////////////
    ll t;
    cin>>t;
    while(t--)
    {
        ll no_of_digits = 0;
    ll n;
    cin>>n;
    ll temp = n,temp1 = n;
    while(temp)
    {
        no_of_digits += 1;
        temp /= 10;
    }
    ll a[no_of_digits];
    for(ll i=0;i<no_of_digits;i++)
    {
        a[i] = temp1%10;
        temp1 /= 10;
    }
    vector <string> ans;
    for(ll i=0;i<no_of_digits;i+=3)
    {
        string tempo = "";
        if((i+3) > no_of_digits)
        {
            ll index = no_of_digits - 1;
            if(index == i)
            {
                if(a[index] != 0)
                {
                    tempo = tempo + mp[a[index]] + " ";
                }
            }
            else
            {
                ll h = a[index]*10 + a[index-1];
                if(h != 0)
                    tempo = tempo + mp[h] + " ";
            }
            if((i>=3) && (tempo != ""))
            {
                ll g = pow(10,i);
                tempo = tempo + mp[g] + " ";
            }
        }
        else
        {
            ll index = i+2;
            if(a[index] != 0)
            {
                tempo = tempo + mp[a[index]] + " " + mp[100] + " ";
            }
            index -= 1;
            ll h = a[index]*10 + a[index-1];
            if(h != 0)
                tempo = tempo + mp[h] + " ";
            if((i >= 3) && (tempo != ""))
            {
                ll g = pow(10,i);
                tempo = tempo + mp[g] + " ";
            }
        }
        ans.push_back(tempo);
    }
    if(n == 0)
        ans.push_back(mp[0]);
    reverse(ans.begin(),ans.end());
    for(auto it : ans)
    {
        cout<<it;
    }
    cout<<"\n";
    }
    //////////////////////////////////////////////////////////////////////
    return 0;
}
