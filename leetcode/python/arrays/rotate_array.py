class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)):
            p = (i+k) % len(nums)
            tmp = nums[p]
            nums[p] = nums[i]
            nums[i] = tmp
