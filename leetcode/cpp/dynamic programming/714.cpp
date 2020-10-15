//Best Time to Buy and Sell Stock with Transaction Fee
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int cash[n];
        int hold[n];
        hold[0]=-prices[0];
        cash[0]=0;
        for(int i=1;i<n;i++)
        {
           cash[i]=max(cash[i-1],hold[i-1]+prices[i]-fee);
           //cash[i-1]///not selling just continuing with prev
          // hold[i-1]+prices[i]-fee//selling at i so prev hold +prices[i]-tfee
            hold[i]=max(max(hold[i-1],cash[i-1]-prices[i]),hold[i-1]-fee);
            //hold[i-1]//not buying 
            //cash[i-1]-prices[i]//buying at i
              //  hold[i-1]-fee+profit[i]-profit[i]//selling at i and buying another one
            
        }
        return cash[n-1];
    }
};