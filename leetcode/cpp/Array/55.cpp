//Best approach that is O(n) time complexity and O(1) space complexity 

class Solution {
public:
    bool canJump(vector<int>& nums) {
    int last = nums.length() - 1;
    for (int i = nums.length() - 1; i >= 0; i--) {
            if (i + nums[i] >= last) {
                last = i;
            }
        }
        return last ; 
    }
};
