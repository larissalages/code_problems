int Solution::repeatedNumber(const vector<int> &A) {
    int res=0;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        res=res^A[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        res=res^i;
    }
    if(res>0)
    {
        return res;
    }
    return -1;
}
