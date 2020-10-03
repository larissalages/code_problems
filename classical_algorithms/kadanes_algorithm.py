'''
Kadane's Algorithm is a standard technique used majorly for problems like:

Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.
'''
def kadanes_algorithm(nums):
        max_ending_here = 0
        max_so_far = float('-inf')
        
        for i in range(len(nums)):
            max_ending_here = max_ending_here+nums[i]
            max_so_far = max(max_so_far, max_ending_here)
            
            if max_ending_here < 0:
                max_ending_here = 0
            
        return max_so_far

nums = [-2,1,-3,4,-1,2,1,-5,4]
print(kadanes_algorithm(nums)) # Output= 6

nums = [-1]
print(kadanes_algorithm(nums)) #output= -1