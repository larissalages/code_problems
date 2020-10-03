//method1: 
class Solution {
public:
    bool canWinNim(int n) {
        return n%4;
    }
};

//method2:
class Solution{
public:
	bool canWinNim(int n){
		vector<bool> dp(n+1,false);
		dp[1]=dp[2]=dp[3]=true;
		for(int i=4;i<=n;i++) dp[i]=!dp[i-1] || !dp[i-2] || !dp[i-3];
		return dp[n];
	}
};

//method3
class Solution{
public:
    int maxMin(int n,vector<int>& table1,vector<int>& table2){
        if(table1[n]!=0) return table1[n];
        vector<int> tmp;
        for(int i=1;i<4;i++){
            if(n-i==0) return 1;
            else if(n-i>0) tmp.push_back(minMax(n-i,table1,table2));
        }
        table1[n]=*max_element(tmp.begin(),tmp.end());
        return table1[n];
    }
    int minMax(int n,vector<int>& table1,vector<int>& table2){
        if(table2[n]!=0) return table2[n];
        vector<int> tmp;
        for(int i=1;i<4;i++){
            if(n-i==0) return -1;
            else if(n-i>0) tmp.push_back(maxMin(n-i,table1,table2));
        }
        table2[n]=*min_element(tmp.begin(),tmp.end());
        return table2[n];
    }
    
	bool canWinNim(int n){
        if(n>=134882061)
	        return n%4;
        vector<int> table1(n+1,0),table2(n+1,0);
        return maxMin(n,table1,table2)==1? true: false;
    }
};