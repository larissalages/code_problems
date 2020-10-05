class Solution {
public:
    bool duplicateRange(vector<int> &nums,int l,int r){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=l && nums[i]<=r) ++count;
        }
        return r-l+1<count;
    }
    
    int findDuplicate(vector<int>& nums) {
        int l=1,r=nums.size()-1,mid;
        while(l<r){
            mid=(l+r)/2;
            if(duplicateRange(nums,l,mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};