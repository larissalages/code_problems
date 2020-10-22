//Coin change

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        
        for(auto c : coins){
            for(int x = c; x<=amount; x++){
                dp[x] = min(dp[x], dp[x-c]+1);
            }
        }
        if(dp[amount]==INT_MAX-1){
            return -1;
        }
        return dp[amount];
    }
};
