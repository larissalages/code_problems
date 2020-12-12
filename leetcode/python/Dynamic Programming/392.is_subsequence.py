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

    # Other way to do it
    def isSubsequence2(self, s: str, t: str) -> bool:
        t = iter(t)
        return all(c in t for c in s)



t = 'abcde'
s = "bb"

print(Solution().isSubsequence2(s, t))
