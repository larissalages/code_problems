class Solution {
public:
    void helper(vector<int>& candidates,vector<vector<int>>& ans,vector<int>& combination,int target,int start){
        if(target==0){
            ans.push_back(combination);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(candidates[i]>target) break;
            combination.push_back(candidates[i]);
            helper(candidates,ans,combination,target-candidates[i],i);
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        helper(candidates,ans,combination,target,0);
        return ans;
    }
};