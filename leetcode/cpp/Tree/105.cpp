class Solution {
    unordered_map<int, int > mp;
public:
    TreeNode* buildTree_util(vector<int>& preorder, int pre1, int pre2 , vector<int>& inorder, int i1, int i2) {
        if(pre1 > pre2 || i1 > i2)
            return NULL;
        TreeNode *root = new TreeNode(preorder[pre1]);
        int diff = mp[preorder[pre1]] - i1;
        root->left = buildTree_util(preorder, pre1 + 1, pre1+diff, inorder, i1, i1+diff-1);
        root->right = buildTree_util(preorder, pre1 +diff+1, pre2 , inorder, i1+diff+1, i2);
        
        return root;
    }
        
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if(n == 0)
            return NULL;
        for(int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        return buildTree_util(preorder, 0, n-1, inorder,0, n-1);
        
    }
};
