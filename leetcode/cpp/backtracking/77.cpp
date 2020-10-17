class Solution {
public:
    //prototype: f will take the sub-problem, the result data structure implicitly and the contribution set
    void helper(int startNum, int& n, int k, vector<vector<int>>& res, vector<int> currSet){
        //base case
        //here we have a 2D sub-problem
        if (k == 0){
            res.push_back(currSet);
            return;
        }
        
        if (startNum == n+1){
            return;
        }
        
       
        //recursive case
        for (int i= startNum ; i<=n-k+1 ; i++){//i+k+1<=n, as we need to include i as well
            currSet.push_back(i);
            helper(i+1, n, k-1,res, currSet);
            currSet.pop_back();//currset will only involve i, because it is not passed with reference and it will remain as a local variable in each stack
        }

    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> currSet;
        helper(1,n, k, res, currSet);
        return res;
    }
};

//=================================
//Time complexity for the above algorithm asymptotically: O(2^n) where n is the size of the input array

//Space complexity: O(n)