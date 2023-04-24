class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int i,j;
    int n = A.size();
    for(i = n - 2;i >= 0;i --)
    {
        if(A[i] < A[i + 1])
            break;
    }
    if(i == -1)
    {
        reverse(A.begin(),A.end());
        return ;
    }

    for(j = n - 1;j > i;j --)
    {
        if(A[j] > A[i])
            break;
    }
    swap(A[j],A[i]);
    reverse(A.begin() + i + 1,A.end());
    return ;
    }
};
