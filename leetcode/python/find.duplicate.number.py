class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        tortoise = nums[0]
        hare = nums[0]
        # do {
        #     tortoise = nums[tortoise]
        #     hare = nums[nums[hare]]
        # } while (tortoise != hare)
        while 1:
            tortoise = nums[tortoise]
            hare = nums[nums[hare]]
            if tortoise==hare:
                break
        ptr1 = nums[0]
        ptr2 = hare
        while (ptr1 != ptr2):
            ptr1 = nums[ptr1]
            ptr2 = nums[ptr2]
        return ptr1;