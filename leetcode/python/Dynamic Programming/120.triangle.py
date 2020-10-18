class Solution:
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        size = len(triangle);
        num = [0]*size;
        num[0] = triangle[0][0];
        for i in range(1,size):
            num[i] = num[i-1] + triangle[i][i];
            j = i - 1
            while j > 0:
                num[j] = min(num[j], num[j-1]) + triangle[i][j];
                j -= 1;
            num[0] = num[0] + triangle[i][0];
        minm = num[0];
        for i in range(1,size):
            minm = min(num[i], minm);
        return minm;
