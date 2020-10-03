//brute force
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        bool flag;
        for(int i=0;i<nums.size();i++){
            flag=1;
            if(i>0) flag&=(nums[i]>nums[i-1]);
            if(i<nums.size()-1) flag&=(nums[i]>nums[i+1]);
            if(flag) return i;
        }
        return -1;
    }
};

//binary search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid;
        while(l+1<r){
            mid=(l+r)/2;
            if(nums[mid]<nums[mid+1]) l=mid;
            else if(nums[mid]<nums[mid-1]) r=mid;
            else return mid;
        }
        if(nums[l]>nums[r]) return l;
        return r;
    }
};