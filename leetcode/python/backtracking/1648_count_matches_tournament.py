class Solution(object):
    def numberOfMatches(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 2:
            return 1
        if n % 2 == 0:
            return self.numberOfMatches(n//2) + n//2
        else:
            return self.numberOfMatches((n-1)//2 +1) + (n-1)//2