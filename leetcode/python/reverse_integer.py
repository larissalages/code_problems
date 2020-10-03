# Given a 32-bit signed integer, reverse digits of an integer.

# Example 1:

# Input: 123
# Output: 321
# Example 2:

# Input: -123
# Output: -321
# Example 3:

# Input: 120
# Output: 21
# Note:
# Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

# A very bad solution
class Solution:
    def reverse(self, x: int) -> int:
        if x >= 2**31-1 or x <= -2**31: return 0
        str_int = str(x)
        new_str = []
        if str_int[0] == '-':
            new_str.append(str_int[0])
            start = 1
        else:
            start = 0
            
        i = len(str_int) -1
        
        str1 = "" 
        while (i >= start):
            new_str.append(str_int[i]) 
            i = i-1
        reverse = int(str1.join(new_str))
        if reverse >= 2**31-1 or reverse <= -2**31: return 0
        return int(str1.join(new_str))
 
# Solution 2
# Time Complexity: O(log(x))
# Space Complexity O(1)
INT_MAX = 2**31-1
INT_MIN = -2**31
class Solution:
    def reverse(self, x: int) -> int:
        if x >= INT_MAX or x <= INT_MIN: return 0
        if x == 0: return x
        if x < 0:
            mult = -1
            x = x*(-1)
        else:
            mult = 1
        
        rev = 0
        num = x
        while(num != 0 ):
            dig = num % 10
            num = num // 10
            if rev > INT_MAX/10: 
                return 0
            else: 
                rev = rev*10 + dig        
        return rev*mult
            