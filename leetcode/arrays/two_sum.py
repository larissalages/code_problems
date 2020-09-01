# Given an array of integers, return indices of the two numbers such that they add up to a specific target.

# You may assume that each input would have exactly one solution, and you may not use the same element twice.

# Example:

# Given nums = [2, 7, 11, 15], target = 9,

# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].

# Solution 1: O(n^2) in time
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if (nums[i] + nums[j]) == target:
                    return [i, j]

# Solution 2: O(n) in time
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}
        for i in range(len(nums)):
            hash_map[nums[i]] = i
        
        for i in range(len(nums)):
            complement = target - nums[i]
            if (complement in hash_map and hash_map[complement] != i):
                    return [i, hash_map[complement]]

# Solution 3: O(n) in time
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}
        for i in range(len(nums)):
            complement = target - nums[i]
        
            if (complement in hash_map and hash_map[complement] != i):
                return [hash_map[complement], i]
            hash_map[nums[i]] = i