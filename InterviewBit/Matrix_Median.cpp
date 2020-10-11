int Solution::findMedian(vector<vector<int> > &A) {
    for(int i=A.size()-1;i>0;i--){
    for(int j=0;j<A[i].size();j++) A[0].push_back(A[i][j]);
    A[i].clear();
}
sort(A[0].begin(),A[0].end());
int n=A[0].size();
if(n%2==0)
{
    return (A[0][n/2]+A[0][(n/2)-1]);
}
return A[0][(n/2)];
}
