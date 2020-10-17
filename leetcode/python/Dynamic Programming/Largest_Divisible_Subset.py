# Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

# Si % Sj = 0 or Sj % Si = 0.

# If there are multiple solutions, return any subset is fine.

# Example 1:

# Input: [1,2,3]

# Output: [1,2] (of course, [1,3] will also be ok)

# Example 2:

# Input: [1,2,4,8]

# Output: [1,2,4,8]
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if len(nums) < 2:
            return nums
        
        #creating a monotonic sequence of list
        nums.sort()
        
        dp = [1]*len(nums)
        max_ind = 0
        
        #dp pass using the following condition
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i]%nums[j] == 0:
                    dp[i] = max(dp[i], dp[j] + 1)
                if dp[max_ind] < dp[i]:
                    max_ind = i
        
        res = []
        res.append(nums[max_ind])
        
        prev = nums[max_ind]

        #reconstructing the sequence by iterating backwards
        for i in range(max_ind - 1, -1, -1):
            if dp[i] > 0 and dp[max_ind]-1 == dp[i] and prev%nums[i] == 0:
                res.append(nums[i])
                prev = nums[i]
                max_ind = i
                
        res.reverse()
        return res