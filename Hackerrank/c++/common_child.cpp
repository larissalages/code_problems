#include <bits/stdc++.h>
using namespace std;
int lcsHelper(char *s1, char *s2, int m, int n, int **dp)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (dp[m][n] > -1)
    {
        return dp[m][n];
    }
    int ans;
    if (s1[0] == s2[0])
    {
        ans = 1 + lcsHelper(s1 + 1, s2 + 1, m - 1, n - 1, dp);
    }
    else
    {
        int option1 = lcsHelper(s1 + 1, s2, m - 1, n, dp);
        int option2 = lcsHelper(s1, s2 + 1, m, n - 1, dp);
        ans = max(option1, option2);
    }
    dp[m][n] = ans;
    return ans;
}
int lcs(char *s1, char *s2)
{
    int m = strlen(s1);
    int n = strlen(s2);
    int **dp = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    int ans = lcsHelper(s1, s2, m, n, dp);
    for (int i = 0; i <= m; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}
int main()
{

    char s1[5010], s2[5010];
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << endl;
    return 0;
}
