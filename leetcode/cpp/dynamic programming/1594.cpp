//DP solution
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int mod=1e9+7;
        int m=grid.size(),n=grid[0].size();
        vector<vector<long long>> mn(m,vector<long long> (n)),mx(m,vector<long long> (n));
        mn[0][0]=mx[0][0]=grid[0][0];
        for(int i=1;i<m;i++) mn[i][0]=mx[i][0]=mx[i-1][0]*grid[i][0];
        for(int j=1;j<n;j++) mn[0][j]=mx[0][j]=mx[0][j-1]*grid[0][j];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]<0){
                    mx[i][j]=min(mn[i-1][j],mn[i][j-1])*grid[i][j];
                    mn[i][j]=max(mx[i-1][j],mx[i][j-1])*grid[i][j];
                }else{
                    mx[i][j]=max(mx[i-1][j],mx[i][j-1])*grid[i][j];
                    mn[i][j]=min(mn[i-1][j],mn[i][j-1])*grid[i][j];
                }
            }
        }
        return mx[m-1][n-1]<0? -1: mx[m-1][n-1]%mod;
    }
};

//dfs solution
class Solution {
public:
    void dfs(vector<vector<int>> &grid,int i,int j,long long curr,long long &product){
        if(i==grid.size()-1 && j==grid[0].size()-1){
            product=max(curr,product);
            return;
        }
        if(grid[i][j]==0){
            product=max(product,(long long)0);
            return;
        }
        if(i+1<grid.size()) dfs(grid,i+1,j,curr*grid[i+1][j],product);
        if(j+1<grid[0].size()) dfs(grid,i,j+1,curr*grid[i][j+1],product);
    }
    
    int maxProductPath(vector<vector<int>>& grid) {
        long long int mod=1e9+7;
        long long product=-1;
        dfs(grid,0,0,grid[0][0],product);
        return product%mod;
    }
};