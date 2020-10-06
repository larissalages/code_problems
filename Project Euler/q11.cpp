#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mat[20][20];
    for(ll i=0;i<20;i++)
    {
        for(ll j=0;j<20;j++)
            cin>>mat[i][j];
    }
    ll maxi = -1,prod;
    for(ll i=0;i<20;i++)
    {
        for(ll j=0;j<17;j++)
        {
            prod = mat[i][j]*mat[i][j+1]*mat[i][j+2]*mat[i][j+3];
            maxi = max(maxi,prod);
        }
    }
    for(ll i=0;i<20;i++)
    {
        for(ll j=0;j<17;j++)
        {
            prod = mat[j][i]*mat[j][i+1]*mat[j][i+2]*mat[j][i+3];
            maxi = max(maxi,prod);
        }
    }
    for(ll i=0;i<17;i++)
        {
            for(ll j=0;j<17;j++)
            {
                prod = mat[i][j]*mat[i+1][j+1]*mat[i+2][j+2]*mat[i+3][j+3];
                maxi = max(maxi,prod);
            }
        }
    for(ll i=0;i<17;i++)
    {
        for(ll j=3;j<=19;j++)
        {
            prod = mat[i][j]*mat[i+1][j-1]*mat[i+2][j-2]*mat[i+3][j-3];
            maxi = max(maxi,prod);
        }
    }
    cout<<maxi<<"\n";
    return 0;
}
