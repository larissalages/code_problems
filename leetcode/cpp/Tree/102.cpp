/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void levelTraverse(TreeNode* node,int level,vector<int> &levelElems){
        if(!node) return;
        if(level==1){
            levelElems.push_back(node->val);
        }else{
            levelTraverse(node->left,level-1,levelElems);
            levelTraverse(node->right,level-1,levelElems);
        }
    }
    
    int height(TreeNode* node){
        if(!node) return 0;
        return max(height(node->left),height(node->right))+1;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        vector<int> levelElems;
        int h=height(root);
        for(int level=1;level<=h;level++){
            levelElems.clear();
            levelTraverse(root,level,levelElems);
            v.push_back(levelElems);
        }
        return v;
    }
};