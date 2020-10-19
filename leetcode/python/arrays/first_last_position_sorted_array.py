class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        res= [-1]*2
        lo= 0
        n= len(nums)
        hi= n-1
        if (n==0):
            return res
        while (lo<hi):
            mid= lo + (hi-lo)//2
            if (nums[mid]>= target):
                hi= mid
            else:
                lo= mid+1
        
        
        if (nums[lo]!=target):
            return res
        res[0]= lo #found lower bound
        
        
        lo= 0
        hi= n-1
        
        while (lo<hi):
            mid= lo +(hi-lo+1)//2
            
            if (nums[mid]> target):
                hi= mid-1
            else:
                lo= mid
        
        res[1]= lo#upper bound
        return res
        
        
        
"""
Time complexity: O(log(n))
Space complexity: O(1), constant space

Find more details of the framework used here: https://www.topcoder.com/community/competitive-programming/tutorials/binary-search/

"""