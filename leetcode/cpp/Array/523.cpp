class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
     unordered_map<int,int>m;
        
                
        int sum=0;
        for(int i=0;i<nums.size();i++){
            
            sum+=nums[i];
            if(k!=0)
                sum%=k;
            
            if(m.find(sum)!=m.end())
            {
                if(i-m[sum] > 1)
                    return 1;
            }
            else m[sum]=i;
        }
        
        return 0;
    }
};