class Solution {
public:
    int height(TreeNode* node){
        if(!node) return 0;
        return max(height(node->left),height(node->right))+1;
    }
    
    void traverseLevel(TreeNode* node,int level,vector<int> &temp){
        if(!node) return;
        if(level==1) temp.push_back(node->val);
        traverseLevel(node->left,level-1,temp);
        traverseLevel(node->right,level-1,temp);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        vector<int> temp;
        int h=height(root);
        for(int level=h;level>0;level--){
            traverseLevel(root,level,temp);
            v.push_back(temp);
            temp.clear();
        }
        return v;
    }
};