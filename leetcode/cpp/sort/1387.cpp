//method1:
class Solution {
public:
    int get(int val, vector<int>& dp)
    {
        if (val < dp.size() && dp[val] != INT_MAX)
            return dp[val];

        auto next = val % 2 ? 3 * val + 1 : val / 2;
        auto result = get(next, dp) + 1;

        if (val < dp.size())
            dp[val] = result;

        return result;
    }


    int getKth(int lo, int hi, int k) 
    {
        vector<int> dp(hi * 3 + 2, INT_MAX);
        dp[1] = 0;

        vector<pair<int, int>> vals;

        for (int i = lo; i <= hi; ++i)
            vals.push_back({get(i, dp), i});

        nth_element(vals.begin(), next(vals.begin(), k - 1), vals.end());
        return vals[k - 1].second;
    }
};

//method2: 

class Solution {
public:
    int power(int x,map<int,int> &powers){
        if(x==1) return 1;
        if(powers.find(x)!=powers.end()) return powers[x];
        if(x%2==0){
            powers[x]=1+power(x/2,powers);
        }else{
            powers[x]=1+power(3*x+1,powers);
        }
        return powers[x];
    }
    
    int getKth(int lo, int hi, int k) {
      map<int,int> powers;
      multimap<int,int> powerArray;
      for(int i=lo;i<=hi;i++){
          powerArray.insert(pair<int,int> (power(i,powers)-1,i));
      }
      for(auto &it: powerArray){
          k--;
          if(!k){
            ans=it.second;
            break;
          }
      }
      return ans;
    }
};