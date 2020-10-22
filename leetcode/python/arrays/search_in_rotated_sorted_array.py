class Solution(object):
    @staticmethod
    def searchHelper(nums,lo,hi,target):
        while lo<=hi:
            mid= lo + (hi-lo)/2
            if nums[mid]==target:
                return mid
            elif nums[mid]>target:
                hi= mid-1
            else:
                lo= mid+1
        return -1

    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        n= len(nums)
        lo= 0
        hi= n-1
        if n==0:
            return -1
        
        while (lo<hi):
            mid= lo+ (hi-lo)/2
            if (nums[mid]<nums[0]):
                hi= mid
            else:
                lo= mid+1
        minm= lo
        #lo is the index of the minimum element

        #now we have 2 sorted(ascending) subarrays, thus do a binary search on each of them
        
        if (nums[lo]==target):
            return lo
        
        else:
            #simple binary search on nums[0:lo-1]
            resIdx= Solution.searchHelper(nums, 0, minm-1, target)
            if (resIdx!=-1):
                return resIdx
            #not found in the first part
            resIdx= Solution.searchHelper(nums, minm, n-1, target)

            #binary search on nums[lo+1,n-1] second part
            
        
        return resIdx#target not found anywhere
    
    
'''
    Time complexity of the algorithm(asymptotically): 
                            O(log(n)), where n is the size of the input array
    Space complexity is constant, O(1)
Find more details of the framework used here: https://www.topcoder.com/community/competitive-programming/tutorials/binary-search/

'''