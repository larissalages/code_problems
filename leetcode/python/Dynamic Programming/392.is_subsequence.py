class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        pc = 0
        count = 0
        for j in range(0, len(t)):
            for it in range(pc, len(s)):
                if t[j] == s[it]:
                    if it == pc or it == pc + 1:
                        pc = it
                        count += 1
                    else:
                        return False
        if count == len(s):
            return True
        else:
            return False


t = 'abcde'
s = 'ace'
print(Solution().isSubsequence(s, t))
