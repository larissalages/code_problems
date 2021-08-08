# Approach 1
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        i = 0
        maxprofit = 0
        v = prices[0]
        p = prices[0]
        while i < len(prices) - 1:
            while i < len(prices) - 1 and prices[i] > prices[i + 1]:
                i += 1
            v = prices[i]
            i += 1
            while i < len(prices) - 1 and prices[i] < prices[i + 1]:
                i += 1
            if i < len(prices):
                p = prices[i]
                i += 1
                maxprofit += p - v

        return maxprofit


# Approach 2
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxprofit = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                maxprofit += prices[i] - prices[i - 1]

        return maxprofit