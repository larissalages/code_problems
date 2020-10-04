#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, m;
    cin >> t;
    string s = "NO";
    while (t--)
    {
        cin >> n >> m;
        int count = 0;
        int a, b, c, d;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            cin >> c >> d;
            if (b == c)
                count++;
        }
        if (count > 0 && m % 2 == 0)
            s = "YES";
        else
        {
            s = "NO";
        }

        cout << s << "\n";
    }
    return 0;
}