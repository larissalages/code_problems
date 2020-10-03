class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,ans=INT_MIN;
        for(auto i:nums){
            sum+=i;
            ans=max(ans,sum);
            sum=max(sum,0);
        }
        return ans;
    }
};