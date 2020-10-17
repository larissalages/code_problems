class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int l = 0,r=0;
        int sum = 0;
        while (r<n){
            sum+=nums[r];
            
            while (sum>=s){
                ans= min(ans,r-l+1);
                sum-=nums[l++];
            }
            r++;
            
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};

//======================================================
//Time complexity of the above algorithm asymptotically: O(n), n is the size of the input array. 
//The reason is because in the worse case, every element will be visited only twice.

//Space complexity: O(1), constant