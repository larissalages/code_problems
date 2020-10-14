int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    int n=A.size();
    if(A[n-1]==0)
    {
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        if(A[i]==(n-i-1))
        {
            if(A[i]!=A[i+1])
            {
                return 1;
            }
        }
    }
    return -1;
}
