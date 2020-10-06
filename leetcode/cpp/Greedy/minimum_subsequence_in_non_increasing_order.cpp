/**
 * Problem link: https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
 * Solution: 
 * (1) Find the sum of all the elements of the vector.
 * (2) Sort the vector in descending order.
 * (3) Keep on subtracting the elements from the highest to lowest (greedily) until the sum of highest  elements is greater than the remaining. Also,add the elements to the answer vector.
 * (4) The required elements till the condition meets is the final answer.
 * (5) Return them in non decreasing order.
 */

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int tot = 0;
        for(int i=0 ; i<n ; i++) tot += nums[i];
        
        vector<int> ans;
        int sum = 0;
        
        for(int i=n-1 ; i>=0 ; i--) {
            sum += nums[i];
            int sumNonAns = tot-sum;
            
            if (sum > sumNonAns) {
                for (int j=n-1 ; j>=i ; j--) ans.push_back(nums[j]);
                return ans;
            }
        }
        
        return nums;
    }
};
