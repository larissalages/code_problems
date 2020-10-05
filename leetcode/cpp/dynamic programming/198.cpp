//top down / memoization
class Solution {
public:
    int DP(vector<int> &nums,int i,vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(nums[i]+DP(nums,i+2,dp),DP(nums,i+1,dp));
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return DP(nums,0,dp);
    }
};

//bottom up/tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size()+1);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++) dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        return dp[nums.size()-1];
    }
};

//most efficient O(n), O(1)
class Solution{
public:
	int rob(vector<int>& nums){
		int sum1=0,sum2=0;
		for(int i=0;i<nums.size();i++){
			if(i&1) sum1=max(nums[i]+sum1,sum2);
			else sum2=max(nums[i]+sum2,sum1);
		}
		return max(sum1,sum2);
	}
};