/*
Description:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Solution: We will use binary search method to find out the better solution

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000

*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // base case to remember 
        if(nums2.size()<nums1.size()) 
            return findMedianSortedArrays(nums2,nums1);
        
        // taking length of both the vector
        int n1=nums1.size();
        int n2=nums2.size();
        
        // initializing two variable low =0 and high=n1(length of nums1)
        int low=0,high=n1;
        

        // iterating through while loop
        while(low<=high){
            
            int cut1=(low+high)/2;
            int cut2=(n1+n2+1)/2-cut1;
            
            int left1=cut1==0?INT_MIN:nums1[cut1-1];
            int left2=cut2==0?INT_MIN:nums2[cut2-1];
            
            int right1=cut1==n1?INT_MAX:nums1[cut1];
            int right2=cut2==n2?INT_MAX:nums2[cut2];
            
            if(left1<=right2 and left2<=right1){               // remember this case
                if((n1+n2)%2==0)
                    return (max(left1,left2)+min(right1,right2))/2.0;
                
                else
                    return max(left1,left2);
            }
            
            else if(left1>right2){
                high=cut1-1;
            }
            
            else{
                low=cut1+1;
            }
        }
        
        return 0.0;
    }
};

