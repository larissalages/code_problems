class Solution {
private : unordered_map<int, int> mp;
public:
    TreeNode* buildTree_util(vector<int>& inorder, int  i1, int i2, vector<int>& postorder, int p1, int p2){
        if(i1 > i2 || p1 > p2)
            return NULL; 
        TreeNode* root = new TreeNode(postorder[p2]);
        int diff = mp[postorder[p2]] - i1;
        root->left = buildTree_util(inorder, i1 , i1+diff-1, postorder, p1, p1+diff-1);
        root->right = buildTree_util(inorder, i1+diff+1, i2, postorder, p1+diff, p2-1);
        
        return root;
        
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n == 0) return NULL;
        for(int i = 0; i < n; i++) 
            mp[inorder[i]] = i;  //(inorder, index)
        
        return buildTree_util(inorder, 0, n-1, postorder, 0, n-1);
    }
};
