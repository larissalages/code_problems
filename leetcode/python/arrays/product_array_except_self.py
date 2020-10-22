class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n= len(nums)  
        prodSoFar= 1    #running product
        output = [nums[n-1]]*n
        
        #preprocessing the array
        for i in range(n-2,-1,-1):
            output[i]= output[i+1]*nums[i]
        

        for i in range(n-1):
            output[i]= prodSoFar*output[i+1]
            prodSoFar*= nums[i]
        
        output[n-1]= prodSoFar
        
        return output
    
    

'''

Time complexity of the above algorith: O(n), n is the length of the input array

Space complexity: O(1), constant space
'''