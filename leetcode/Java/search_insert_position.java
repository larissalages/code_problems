#Java Solution

class Solution {
public int searchInsert(int[] nums, int target) {

    int size = nums.length;
    //If element is present in the array
    for(int i=0;i<size;i++){
        if(nums[i] == target)
            return i;
    }
    int j=0;
    //If element is not there in the array
    for(int i=0;i<size;i++){
        if(nums[i] < target){
             j++;
        }else{
            break;
        }    
    }
    return j;
    
}
}
