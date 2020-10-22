class Solution {
public:
    //f will take the input array, the index or the position of the element on which we need to take the decision and the result vector of vectors
    void helper(vector<int>&nums, int startIndex, vector<vector<int>>& res){
        int n= nums.size();
        //base case
        if (startIndex==n){
            res.push_back({});
            return;
        }
        //f(ar,startIndex)= f(ar,startIndex+1) U {nums[startIndex] U f(ar.startIndex+1)}
        vector<vector<int>> subSol;
        helper(nums, startIndex+1, res);
        
        //exclude the startIndex
        subSol= res;
        
        //include the startIndex
        vector<int> temp;
        for (int i=0;i<subSol.size();i++){
            temp= subSol[i];
            temp.push_back(nums[startIndex]);
            res.push_back(temp);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums,0,res);
        return res;
    }
};

//=================================
//Time complexity for the above algorithm asymptotically: O(2^n) where n is the size of the input array

//Space complexity: O(n)