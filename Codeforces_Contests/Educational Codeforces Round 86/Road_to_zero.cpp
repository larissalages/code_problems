#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        ll a, b;
        cin >> a >> b;
        ll cost = 0;
        if (b < 2 * a)
        {
            if(x>y){
                cost+=(y*b);
                x-=y;
                cost+=(x*a);
            }else{
                cost+=(x*b);
                y-=x;
                cost+=(y*a);
            }
        }else{
            cost+=(x+y)*a;
        }
        cout << cost << endl;
    }
    return 0;
}