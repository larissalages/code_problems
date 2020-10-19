class Solution {
public:
    string rankTeams(vector<string>& votes) {
        //rank matrix
        int i,j,n= votes.size(),k= votes[0].size(); 
        vector<vector<int>> rank(26, vector<int>(k,0));
        for (i=0;i< n;i++){
            for (j=0;j<k;j++){
                rank[votes[i][j]-'A'][j]++;
            }
        }
        string res= votes[0];
        sort(res.begin(),res.end(),[&rank](char &a, char &b){
            int i=0;//index for both the rows of that 2 teams
            int n= rank[a-'A'].size();
            while (i<n  && rank[a-'A'][i]==rank[b-'A'][i]){
                i++;//lkeep on going till there is a mismatch of votes
            }
            if (i==n)
                return a<b;//if everything is equal, arrange them alphabetically
            return rank[a-'A'][i]>rank[b-'A'][i];
        
        
        });
            return res;
        
    }
};
//==========================================================
//Time complexity of the algorithm asymptotically: O(n(k+log(n)))
//Space complexity: O(n*k)