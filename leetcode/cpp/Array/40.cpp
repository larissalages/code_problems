class Solution {
public:
    void helper(vector<int>& candidates,vector<int>& combination,vector<vector<int>>& ans,int target,int start){
        if(target==0){
            ans.push_back(combination);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(candidates[i]>target) break;
            if(i>start && candidates[i]==candidates[i-1]) continue;
            combination.push_back(candidates[i]);
            helper(candidates,combination,ans,target-candidates[i],i+1);
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        helper(candidates,combination,ans,target,0);
        return ans;
    }
};