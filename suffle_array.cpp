class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
     
    vector<int> muth;
        
        for(int i=0;i<n;i++)
        {
            muth.push_back(nums[i]);
            muth.push_back(nums[i+n]);
        }
        return muth;
    }
};
