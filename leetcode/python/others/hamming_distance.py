class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        count = 0
        diff = x ^ y
        while diff != 0:
            count += 1
            diff &= (diff-1)
        return count
