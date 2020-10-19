// Minimum Cost for Tickets

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n_days = (int)days.size();
        int last_day = days[n_days - 1];
        vector<int> cost(last_day + 1,0);
        int j = 0;
        int z = 0;
        for(int i = 1; i <= last_day; i++){
            if(days[j] == i){
                j++;
                int a = INT_MAX, b = INT_MAX, c = INT_MAX;
                a = cost[i - 1] + costs[0];
                b = cost[max(z, i - 7)] + costs[1];
                c = cost[max(z, i - 30)] + costs[2];
                cost[i] = min({a, b, c});
            }
            else cost[i] = cost[i-1];
        }

        return cost[last_day];
    }
};
