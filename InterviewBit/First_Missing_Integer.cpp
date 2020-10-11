int Solution::firstMissingPositive(vector<int> &A) {
    sort(A.begin(),A.end());
    int m=0;
    while(A[m]<1)
    {
        m+=1;
    }
    if(A[m]!=1)
    {
        return 1;
    }
    int num=A[m];
    for(int i=m+1;i<A.size();i++)
    {
        if(A[i]!=(num+1))
        {
            return num+1;
        }
        num+=1;
    }
    return num+1;
}
