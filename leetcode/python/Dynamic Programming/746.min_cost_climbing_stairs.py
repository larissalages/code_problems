# On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
#
# Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
#
# Example 1:
# Input: cost = [10, 15, 20]
# Output: 15
# Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
# Example 2:
# Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
# Output: 6
# Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].


class Solution:
    def __init__(self):
        self.mem_cost = []

    def _init_mem_cost(self, x):
        self.mem_cost = [-1] * x

    def calculateCost(self, i, cost):
        if i == 0 or i == 1:
            return cost[i]
        if self.mem_cost[i] != -1:
            return self.mem_cost[i]
        else:
            if i + 1 == len(cost):
                c_1 = self.calculateCost(i - 1, cost)
                c_2 = self.calculateCost(i - 2, cost)
                if c_1 < c_2 + cost[i]:
                    return c_1
                else:
                    return c_2 + cost[i]
            else:
                self.mem_cost[i] = min(self.calculateCost(i - 1, cost), self.calculateCost(i - 2, cost)) + cost[i]
                return self.mem_cost[i]

    def minCostClimbingStairs(self, cost) -> int:
        self._init_mem_cost(len(cost))
        return self.calculateCost(len(cost)-1, cost)


cost = [0, 0, 1, 1]
print(Solution().minCostClimbingStairs(cost))
