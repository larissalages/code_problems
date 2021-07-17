class Solution:

    ####### Solution 1 #######
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return n
        first = 1
        second = 2
        for i in range(3, n + 1):
            third = first + second
            first = second
            second = third
        return second

    ####### Solution 2 #######
    def climbStairs(self, n: int) -> int:
        d = []
        d.append(0)
        d.append(1)
        d.append(2)
        for i in range(3, n+1):
            d.append(d[i-1]+d[i-2])
        return d[n]

    ####### Solution 3 #######

    def climbStairs(self, n: int) -> int:
        memo = {}
        return self.step_n(n, memo)

    def step_n(self, n, memo):
        if n <= 2:
            return n
        if n in memo:
            return memo[n]
        res = self.step_n(n-1, memo) + self.step_n(n-2, memo)
        memo[n] = res
        return res
