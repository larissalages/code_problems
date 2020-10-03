//bit manipulation method
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result=0,n=nums.size();
        vector<int> v(32,0);
        for(int i=0;i<32;i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j]&(1<<i)) v[i]+=1;
            }
        }
        for(int i=0;i<32;i++){
            if(v[i]>n/2) result|=(1<<i);
        }
        return result;
    }
};

//moore's voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem,count=0;
        for(auto num: nums){
            if(count==0) elem=num;
            if(elem==num) count++;
            else count--;
        }
        return elem;
    }
};