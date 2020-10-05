//method1: dfs
class Solution {
public:
    void findPaths(TreeNode* node,int sum,vector<vector<int>> &v,vector<int> temp){
        if(!node) return;
        temp.push_back(node->val);
        if(!node->left && !node->right){
            if(node->val==sum) v.push_back(temp);
        }
        findPaths(node->left,sum-node->val,v,temp);
        findPaths(node->right,sum-node->val,v,temp);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> v;
        vector<int> temp;
        findPaths(root,sum,v,temp);
        return v;
    }
};

//method2: backtracking
class Solution {
public:
    void backtracking(vector<vector<int>> &out, TreeNode* root, int sum, int check, vector<int>&temp){
        if(root == NULL) return ;
        check += root->val ;
        if(check == sum && root->left == NULL && root->right == NULL) out.push_back(temp); 
        if (root->left) {
            temp.push_back(root->left->val); 
            backtracking(out, root->left, sum, check,temp);
            temp.pop_back();
        }
        if (root->right) {
            temp.push_back(root->right->val); 
            backtracking(out, root->right, sum, check,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> out ; 
        vector<int> temp ; 
        if(root == NULL) return out ; 
        temp.push_back (root->val) ;
        backtracking(out, root, sum, 0,temp);
        return out ; 
    }
};