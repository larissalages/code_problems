#include <bits/stdc++.h>
using namespace std;
int max_subsequence(int a[], int n)
{
    int m = a[0], s = 0;
    for (int i = 0; i < n; i++)
    {
        if (m < a[i])
        {
            m = a[i];
        }
        if (a[i] >= 0)
        {
            s += a[i];
        }
    }
    if (m >= 0)
    {
        return s;
    }
    else
    {
        return m;
    }
}
int maxSubArraySum(int a[], int n)
{
    int f = a[0];
    int ans = f;
    for(int i = 1;i < n ; i++){
        f = max(a[i], f + a[i]);
        ans = max(ans, f);
    }
    return ans;
}
vector<int> maximum_subarray(int a[], int n)
{
    vector<int> ans;
    ans.push_back(maxSubArraySum(a, n));
    ans.push_back(max_subsequence(a, n));
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> ans = maximum_subarray(a, n);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
