//************************** it's all about practice ***********************
#include<bits/stdc++.h>
using namespace std;
//**** Abbrevations ****
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
//**** STL ****
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define ALL(x) x.begin(), x.end()
//**** some I/O ****
#define no         cout << "NO\n"
#define yes        cout << "YES\n"
//**** Fast I/O ****
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//**** Short Code ****
#define tc ll t;cin>>t;while(t--)
#define fi(a,b) for(ll i=a;i<b;i++)
#define fj(a,b) for(ll j=a;j<b;j++)
#define fk(a,b) for(ll k=a;k<b;k++)
/*---------------------------------------------------------------------------*/
int main()
{
    FAST_IO
    tc
    {
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        bool c=false;
        int i=x;
        if(x==y)
            c=true;
        else
            i=(i+k)%n;
        while(i!=x)
        {
            if(i==y)
            {
                c=true;
                break;
            }
            else
                i=(i+k)%n;
        }
        if(c==true)
            yes;
        else
            no;

    }
    return 0;
}

