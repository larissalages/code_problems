class Solution {
public:
    //decision is to include the repeated element how many times, 0,1,2,..
    void helper(vector<int> &nums,int startIdx, vector<vector<int>> &res,vector<int> currSet){
        //base case
        int n= nums.size();
        if (startIdx==n){
            res.push_back(currSet);
            return;
        }
        //recursive case
        
        int i,j;
        i= startIdx+1;
        //find the non-repeating index
        while (i<n && nums[i]==nums[i-1]) i++;
        j=i;
        
        
        //include
        helper(nums,j,res,currSet);
        
        //more than 1 times
        for (i=startIdx;i<j;i++){
            currSet.push_back(nums[i]);
            helper(nums,j,res,currSet);
        }
        
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> currSet;
        sort(nums.begin(),nums.end());
        
        helper(nums,0,res,currSet);
        return res;
    }
};

//=================================
//Time complexity for the above algorithm asymptotically: O(2^n) where n is the size of the input array

//Space complexity: O(n)