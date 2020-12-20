class Solution(object):
	# Solution 1: the first shit I thought 
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

	# Solution 2: a smater one
	"""
		There are n teams, and each match makes one team be eliminated. So to eliminated n-1 teams you need n-1 matches.
	"""
	def numberOfMatches2(self, n):
		return n-1

# Solution 3: Just to not use recursion
	def numberOfMatches3(self, n):
		cnt = 0
		while (n > 1):
			cnt += n//2
			n = n//2 + n % 2

		return cnt