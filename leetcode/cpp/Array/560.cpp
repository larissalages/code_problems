class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n= nums.size(),i, cumSum= 0, res=0;
        unordered_map<int,int> m;//<sum till now,count>
        
        m[0]= 1;
        
        for (i=0;i<n;i++){
            cumSum+=nums[i];//update the cumulative sum or the sum of prefix subarray till the curr elem
            res+=m[cumSum-k];//find the required sum and update the result, if it doesnt exist it will return 0
            m[cumSum]++;//update the cumulative sum
            
        }
        return res;
        
    }
};


//======================================================
//Time complexity of the above algorith: O(n), n is the length of the input array

//Space complexity: O(n), because of the hashmap