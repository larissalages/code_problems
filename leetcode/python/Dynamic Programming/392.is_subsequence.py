class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i=0
        for j in range(0, len(t)):
            if i < len(s) and s[i] == t[j]:
                i += 1
        if i == len(s):
            return True
        else:
            return False

t = 'abcde'
s = "bb"

print(Solution().isSubsequence(s, t))
