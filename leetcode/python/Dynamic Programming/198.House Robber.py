class Solution(object):
    def rob(self, nums):
        odd_max = even_max = 0

        for i in range(len(nums)):
            if i % 2 == 0:  # odd case as index for first house is 0
                odd_max = max(odd_max + nums[i], even_max)   # record max val for house values in odd position
            else:
                even_max = max(even_max + nums[i], odd_max)  # record max val for house values in even position

        return max(odd_max, even_max)


if __name__ == '__main__':
    nums = [2,7,9,3,1]
    print(Solution().rob(nums))
