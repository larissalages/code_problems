
/* _       _
   |\     /
   | \   /
   | /  /   _
   |/   \    \
   |     \   /
   |      \_/  */

#include<bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define vll vector <ll>
#define vss vector <string>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define M 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcase ll t;cin>>t;while(t--)
#define fi(a,b) for(ll i=a;i<b;i++)
#define fj(a,b) for(ll j=a;j<b;j++)
#define fk(a,b) for(ll k=a;k<b;k++)

using namespace std;

// ............................................................................................ //


int main()
{
    fast
    testcase
    {
        ll n, k, l, num;
        cin>>n>>k>>l;
        num=n;
        ll j=1;
        if(k*l<n || (k==1 && n>1))
            cout<<"-1"<<endl;

        else
        {
            while(num!=0)
            {
                if(j==k+1)
                    j=1;

                cout<<j<<" ";
                j++;
                num--;
            }
        }
        cout<<endl;
    }
}
