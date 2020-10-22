class Solution:
    def maxCoins(self, iNums):
        nums = [1] + [i for i in iNums if i > 0] + [1]  Clear digital # 0, since 0 is not scored, and then either end, [1], to facilitate the calculation
        n = len(nums)
        dp = [[0] * n for _ in range(n)]  # Initialize dp
        for k in range(2, n):  # K determining the size of a sliding window, from start 2
            for left in range(0, n - k):  # Sliding window, sliding from left to right, determine the start of the interval (left), end (right) position
                right = left + k
                for i in range(left + 1, right):  # Begin enumeration, which number in the range as the last one to be punctured to make it the highest score
                    dp[left][right] = max(dp[left][right], nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right])
        return dp[0][n - 1]


if __name__ == '__main__':
    nums = [3,1,5,8]
    solu = Solution()
    out = solu.maxCoins(nums)
    print(out)
