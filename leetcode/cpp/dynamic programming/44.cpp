class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        int i,j;
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(i=0;i<=m;i++)
        {
            for(j=0;j<=n;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=1;
                else if(j==0)
                    dp[i][j]=0;
                else if(i==0)
                {
                    if(p[j-1]=='*')
                    dp[i][j]=dp[i][j-1];
                }
                else 
                {
                    if(s[i-1]==p[j-1] || p[j-1]=='?')
                        dp[i][j]=dp[i-1][j-1];
                    else if(p[j-1]=='*')
                        dp[i][j]=dp[i-1][j]||dp[i][j-1];
                    else
                        dp[i][j]=0;
                }
            }
        }
        return dp[m][n];
    }
};