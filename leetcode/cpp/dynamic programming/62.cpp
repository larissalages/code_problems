//Unique Paths

class Solution {
public:
    long long comb(int n,int k){
        long long arr[n+1][k+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=min(i,k);j++){
                if(j == 0 || j == i){
                    arr[i][j] = 1; 
                }
                else{
                    arr[i][j] = arr[i-1][j]+arr[i-1][j-1];
                }
            }
        }
        return arr[n][k];
    }
    
    int uniquePaths(int m, int n) {
        return comb(m+n-2,min(m,n)-1);
    }
};