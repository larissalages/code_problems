# Solves LeetCode question 38. Count and Say

class Solution(object):
   def countAndSay(self, n):
      """
      :type n: int
      :rtype: str
      """
      s = "1"
      if n == 1:
         return s
      for i in range(2,n+1):
         j = 0
         temp = ""
         curr = ""
         count = 0
         while j<len(s):
            if curr =="":
               curr=s[j]
               count=1
               j+=1
            elif curr == s[j]:
               count+=1
               j+=1
            else:
               temp+= str(count) + curr
               curr=""
               count = 0
         temp+=str(count) + curr
         s=temp
      return s
ob1 = Solution()
print(ob1.countAndSay(6))