class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int profit=0,max_profit=INT_MIN,min=prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min)
                min=prices[i];
            profit=prices[i]-min;
            if(profit>max_profit)
                max_profit=profit;
        }
        return max_profit;
    }
};