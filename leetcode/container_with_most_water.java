class Solution {
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length - 1;
        int maxCapacity = -1;
        while (left != right){
            int currentCapacity = (right - left)*Math.min(height[left], height[right]);
            if (currentCapacity > maxCapacity){
                maxCapacity = currentCapacity;
            }
            if (height[left] <= height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxCapacity;
    }
}
