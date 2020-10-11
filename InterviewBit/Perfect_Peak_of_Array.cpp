int Solution::perfectPeak(vector<int> &A) {
    int n=A.size();
    vector<int>maxm(n);
    vector<int>minm(n);
    maxm.at(0)=A[0];
    minm.at(n-1)=A[n-1];
    for(int i=1;i<n;i++)
    {
        maxm.at(i)=max(A[i],maxm[i-1]);
    }
    for(int i=n-2;i>=0;i--)
    {
        minm.at(i)=min(A[i],minm[i+1]);
    }
    for(int i=1;i<n-1;i++)
    {
        if(A[i]<minm[i+1]&&A[i]>maxm[i-1])
        {
            return 1;
        }
    }
    return 0;
}
