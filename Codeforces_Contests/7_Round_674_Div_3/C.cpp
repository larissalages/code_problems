#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, rn;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int rn = sqrt(n);
        if (n % rn == 0)
        {
            cout << (n / rn) + rn - 2 << "\n";
        }
        else
        {
            cout << (n / rn) + rn - 1 << "\n";
        }
    }
    return 0;
}