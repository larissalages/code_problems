class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        int sum,ithbit;
        for(int i=0;i<32;i++){
            sum=0;
            ithbit=(1<<i);
            for(int j=0;j<nums.size();j++){
                if(nums[j]&ithbit){
                    sum++;
                }
            }
            if(sum%3) result|=ithbit;
        }
        return result;
    }
};