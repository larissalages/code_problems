int Solution::maximumGap(const vector<int> &A) {
    vector<int>v=A;
    int maxm=0;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++)
    {
        int diff=v[i+1]-v[i];
        maxm=max(diff,maxm);
    }
    return maxm;
}
