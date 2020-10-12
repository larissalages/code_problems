class Solution {
public:
    
    void findElements(int i,int j, vector<vector<int>>& ans, vector<int>& rowSum, vector<int>& colSum){
        if(i>=0 and j>=0 and i<rowSum.size() and j<colSum.size() and ans[i][j]==-1){
            ans[i][j]=min(rowSum[i],colSum[j]);
            rowSum[i]-=ans[i][j];
            colSum[j]-=ans[i][j];
            findElements(i-1,j,ans,rowSum,colSum);
            findElements(i,j-1,ans,rowSum,colSum);
        }
        return;
    }
    
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>>ans(rowSum.size(),vector<int>(colSum.size(),-1));
        for(int i=rowSum.size()-1;i>=0;i--){
            for(int j=colSum.size()-1;j>=0;j--){
                if(ans[i][j]==-1){
                    findElements(i,j,ans,rowSum,colSum);
                }
            }
        }
       
        return ans;
    }
};