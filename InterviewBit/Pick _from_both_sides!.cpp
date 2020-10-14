int Solution::solve(vector<int> &A, int B) 
{
    int sum=0,ans,n=A.size();
    for(int i=n-1;i>=n-B;i--)
    {
        sum+=A[i];
    }
    ans=sum;
    for(int i=0;i<B;i++)
    {
        sum+=A[i]-A[n-B+i];
        ans=max(ans,sum);
    }
    return ans;
}
