from typing import List


class Solution:
    def specialArray(self, nums: List[int]) -> int:
        for i in range(1, len(nums)+1):
            count = 0
            for j in nums:
                if j >= i:
                    count += 1
            if count == i:
                return i
        return -1
