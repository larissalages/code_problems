class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int next=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i])
            {
                nums[next]=nums[i];
                next++;
            }
        }
        for(int i=next;i<nums.size();i++)
        {
           nums[i]=0;
        }
       
    }
};
