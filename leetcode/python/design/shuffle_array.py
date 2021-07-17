import random


class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums
        self.org = nums.copy()

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.org

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        # Fisher Yates Algorithm
        for i in range(0, len(self.nums)):
            idx_2 = random.randint(i, len(self.nums) - 1)
            self.nums[i], self.nums[idx_2] = self.nums[idx_2], self.nums[i]
        return self.nums

        # Or use random.shuffle, it has a better perfomance
        # random.shuffle(self.nums)

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
