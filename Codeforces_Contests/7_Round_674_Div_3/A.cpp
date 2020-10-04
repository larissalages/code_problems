#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, x, f;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        if (n == 1 || n == 2)
            f = 1;
        else
        {
            for (int i = 2, j = 2;; i += x, j++)
            {
                if (n > i && n <= i + x)
                {
                    f = j;
                    break;
                }
            }
        }
        cout << f << "\n";
    }
    return 0;
}