class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> x;
        int ans;
        for(int i=0;i<nums.size();i++)
        {
           x[nums[i]]++;
            if(x[nums[i]]>1)
            {
                ans=nums[i];
            }
        }
        return ans;
    }
};
