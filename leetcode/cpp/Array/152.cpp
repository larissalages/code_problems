class Solution {
public:
     int maxProduct(vector<int>& nums) 
    {
         if(!nums.size()) return 0;
         int mx=nums[0],mn=nums[0],ans=nums[0],x,y;
         for(int i=1;i<nums.size();i++){
             x=nums[i]*mx;
             y=nums[i]*mn;
             mx=max(nums[i],max(x,y));
             mn=min(nums[i],min(x,y));
             ans=max(ans,max(mx,mn));
         }
         return ans;
    }
};