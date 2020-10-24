// Problem 75. Sort Colors
// https://leetcode.com/problems/sort-colors/
// time complexity : O(n) only one traversal needed
// space complexity : O(1)
class Solution {
public:
    void swap(int *x,int *y){
        int temp=*x;
        *x=*y;
        *y=temp;
    }
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            int x=nums[mid];
            if(x==0){
                swap(&nums[low++],&nums[mid++]);
            }
            else if(x==1){
                mid++;
            }
            else if(x==2){
                swap(&nums[mid],&nums[high--]);
            }
        }
    }
};
