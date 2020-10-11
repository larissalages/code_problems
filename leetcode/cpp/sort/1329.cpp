// Problem: https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution {
public:

    // HINT: Difference of j and i is constant across a diagonal.
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n = mat.size();
        if (n <=1) return mat;
        int m = mat[0].size();
        
        map <int, vector<int>> mpp;
        map <int, int> mpp2;
        
        for (int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                
                if(mpp.find(j-i)!=mpp.end()) {
                    
                    vector<int> v = mpp[j-i];
                    v.push_back(mat[i][j]);
                    mpp[j-i] = v;
                } else {
                    
                    vector<int> v;
                    v.push_back(mat[i][j]);
                    mpp[j-i] = v;
                }
                
            }
        }
        
        for (auto it: mpp) {
            
            vector<int> v = it.second;
            sort(v.begin(), v.end());
            mpp[it.first] = v;
            mpp2[it.first] = 0;
        }
        
        for (int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                
                int idx = mpp2[j-i];
                vector<int>v = mpp[j-i];
                mat[i][j] = v[idx];
                mpp2[j-i] = idx+1;
            }
        }
        
        return mat;
    }
};
