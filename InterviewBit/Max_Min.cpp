int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    int s=A.size();
    int sum=A[0]+A[s-1];
    return sum;
}
