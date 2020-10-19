class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:

        if len(A) < 3:
            return 0

        dp = [0 for _ in range(len(A))]
        d = A[1] - A[0]
        start = 2

        next_ = self._count(A, d, dp, start)
        while next_ < len(A):
            d = A[next_] - A[next_ - 1]
            start = next_ + 1
            next_ = self._count(A, d, dp, start)

        return sum(dp)

def _count(self, A, d, dp, start):

        for i in range(start, len(A)):
            if A[i] - A[i - 1] == d:
                dp[i] = dp[i - 1] + 1
            else:
                return i

        return len(A)

 
