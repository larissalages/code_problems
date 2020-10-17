// Problem Link: https://leetcode.com/problems/product-of-array-except-self/

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int [] ans = new int[nums.length];
        ans[0] = 1;
        for(int i=1; i<nums.length; i++)
        {
            ans[i] = ans[i-1] * nums[i-1];
        }
        int R=1;
        for(int i=nums.length - 1; i>=0; i--)
        {
                ans[i] = ans[i] * R;
                R *= nums[i];
        }
        
        return ans;
    }
}
