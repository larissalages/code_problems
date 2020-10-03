class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=1;i<nums.size();i++) nums[0]^=nums[i];
        return nums[0];
    }
};