class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size(), i, prodSoFar= 1;
        vector<int> output(n,nums[n-1]);
        //preprocessing the array
        for (i=n-2;i>=0;i--){
            output[i]= output[i+1]*nums[i];
        }

        for (i=0;i<n-1;i++){
            output[i]= prodSoFar*output[i+1];
            prodSoFar*= nums[i];
        }
        output[n-1]= prodSoFar;
        
        return output;
    }
    
};


//==============================================================
//Time complexity of the above algorith: O(n), n is the length of the input array

//Space complexity: O(1), constant space