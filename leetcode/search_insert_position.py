# Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

# You may assume no duplicates in the array.

# Example 1:

# Input: [1,3,5,6], 5
# Output: 2
# Example 2:

# Input: [1,3,5,6], 2
# Output: 1
# Example 3:

# Input: [1,3,5,6], 7
# Output: 4

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        i = int(len(nums)/2)
        
        if nums[i] > target:
            while(i >= 0 and nums[i] != target and nums[i] > target):
                i-=1
            if nums[i] != target:
                i+=1
        else:
            while(i < len(nums) and nums[i] != target and nums[i] < target):
                i+=1
        return i

# Binary Search
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums)-1
        
        while(l<=r):
            mid = (l+r)/2
            if nums[mid] == target:
                return mid
            if nums[mid] <= target:
                l = mid+1
            else:
                r = mid-1
        return l

index = Solution().searchInsert([1,3,5,6], 5)
print(index)