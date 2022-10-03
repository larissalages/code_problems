class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        v = nums[0]
        idx = k % len(nums)
        for item in nums:
            tmp = nums[idx]
            nums[idx] = v
            v = tmp
            idx = (idx + k) % len(nums)


s = Solution()
s.rotate([1,2,3,4,5,6,7], k=3)

