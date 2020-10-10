//Decode ways

class Solution {
public:
    bool check(string s, int i){
        int num = (s[i-1] - '0')*10 + (s[i] - '0');
        if(num>=10 && num<=26)return true;
        return false; 
    }
    
    int numDecodings(string s) {
        if(s.length() == 0)return 0;
        vector<int> dp(s.length()+1, 0);
        dp[0] = 1;
        if(s[0]>'0'){
            dp[1] = 1;
        }
        else {
            return 0;
        }
        if(s.length() == 1)return s.length();
        for(int i=1;i<s.length();i++){
            if(s[i] == '0' && s[i-1]>'0' && s[i-1]<'3'){
                dp[i+1] = dp[i-1];
            }
            else if(s[i] == '0'){
                return 0;
            }
            else if(check(s, i)){
                dp[i+1] = dp[i-1] + dp[i];
            }
            else{
                dp[i+1] = dp[i];
            }
        }
        return dp[s.length()];
    }
};