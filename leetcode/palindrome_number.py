class Solution:
    def isPalindrome(self, x: int) -> bool:
        i = 0
        str_x = str(x)
        n = len(str_x)
        while i < n-i-1:
            if str_x[i] != str_x[n-i-1]:
                return False
            i += 1
        return True