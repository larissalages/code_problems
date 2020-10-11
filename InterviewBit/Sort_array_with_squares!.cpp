vector<int> Solution::solve(vector<int> &A) {
    vector<int>v;
    for(int i=0;i<A.size();i++)
    {
        v.push_back(A[i]*A[i]);
    }
    sort(v.begin(),v.end());
    return v;
}
