class Solution {
public:
    void reverse(vector<int> &nums, int startIndex, int endIndex)
    {
        //This function reverses the vector for the given start and end Indices of the Vector
        while(startIndex < endIndex)
        {
            int temp = nums[startIndex];
            nums[startIndex] = nums[endIndex];
            nums[endIndex] = temp;
            
            startIndex++;
            endIndex--;
        }
    }
    void rotate(vector<int>& nums, int k) 
    {
        int length = nums.size(); //Stores the Size of the Vector into the length variable
        if(k > length)
        {
            k %= length;           //Making Sure that the Rotation is within the length of the Vector
        }
        if(k == 0 || k == length)   //If k is zero or k is equal to the length of the Vector there is no need to perform operations on it
            return;
        
        //Rotating the Vector with the help of the Reverse Function
        reverse(nums, 0, length - 1);   
        reverse(nums, 0, k - 1);        
        reverse(nums, k, length - 1);
    }
};
