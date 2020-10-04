// This is the solution for Leetcode #662
// link of the question is: https://leetcode.com/problems/maximum-width-of-binary-tree/

// Solution class begins here
class Solution {
public:
// uint64_t is 64 bit unsigned integer
    uint64_t widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
    queue <pair<TreeNode *, uint64_t>> q;
    q.push(make_pair(root, 0));
    uint64_t res=0;
    uint64_t index=0;
    pair<TreeNode*, uint64_t> f;
    pair<TreeNode*, uint64_t> curr;
    while(!q.empty()){
        f = q.front();
        uint64_t count = q.size();
        while(count--){
            curr = q.front();
            q.pop();
            TreeNode *node = curr.first;
            index = curr.second;
            if(node->left!=NULL) q.push(make_pair(node->left, 2*index));
            if(node->right!=NULL) q.push(make_pair(node->right, 2*index + 1));
        }
        res = max(res, curr.second - f.second + 1);
    }
    return res;
    }
};
