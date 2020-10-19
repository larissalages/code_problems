class Solution(object):
    @staticmethod
    def area(i,j,h1,h2):
        return (j-i)*min(h1,h2)
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n= len(height)
        i=0
        j=n-1
        res= 0
        while (i<j):
            res= max(res,Solution.area(i,j,height[i],height[j]))
            #pointer calculation and movement
            
            if (height[i]<height[j]):
                i+=1
            else:
                j-=1
        return res
        