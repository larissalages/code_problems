class Solution {
public:
    void swap(int *x,int *y){
        int temp=*x;
        *x=*y;
        *y=temp;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),temp;
        for(int j=0;j<(n/2);j++){
            for(int i=j;i<(n-1-j);i++){
                temp=matrix[j][i];
                swap(&temp,&matrix[i][n-1-j]);
                swap(&temp,&matrix[n-1-j][n-1-i]);
                swap(&temp,&matrix[n-1-i][j]);
                swap(&temp,&matrix[j][i]);
            }
        }
    }
};