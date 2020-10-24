class Solution {
public:
    void backtrack(vector<vector<int>> &ans,int i,vector<int> nums)
    {
        if(i>=nums.size())
        {
             ans.push_back(nums);          // end of branch of recursion tree
            return;
        }
        
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);           //swaping characters of nums
            backtrack(ans,i+1,nums);
            swap(nums[i],nums[j]); 	     //reswapping it to regain original nums
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans,0,nums);
        return ans;
    }
};


//Time complexity of above problem is 0(n*n!)
//space complexity 0(n*n!)
