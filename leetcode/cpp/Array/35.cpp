//search insert position
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > target) {
                if(i == 0) {
                    return 0;
                } else if(nums[i-1] == target)
                    return i-1;
                else return i;
            }
        }
        return (nums[nums.size()-1]==target)?nums.size()-1:nums.size();
    }
};
