class Solution:
    def hammingWeight(self, n: int) -> int:
        sum_ = 0
        while n != 0:
            sum_ += 1
            n &= (n - 1)

        return sum_
