//method1: using recursion
class Solution {
public:
    int height(TreeNode* node){
        if(!node) return 0;
        return max(height(node->left),height(node->right))+1;
    }
    
    void levelTraverse(TreeNode* node,vector<int> &temp,int level){
        if(!node) return;
        if(level==1) temp.push_back(node->val);
        levelTraverse(node->left,temp,level-1);
        levelTraverse(node->right,temp,level-1);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        vector<int> temp;
        int h=height(root);
        for(int level=1;level<=h;level++){
            levelTraverse(root,temp,level);
            if(level%2==0) reverse(temp.begin(),temp.end());
            v.push_back(temp);
            temp.clear();
        }
        return v;
    }
};

//method2: using queue
vector<vector<int>> zigzag (TreeNode *root){
    queue<pair<int,TreeNode*>> myqueue;
    vector<vector<int>> ans;
    vector<int> temp;
    TreeNode *lc ;
    pair<int,TreeNode*> p;
        
    if( root == NULL){
        return ans;
    }
    
    myqueue.push({0,root});
    while(!myqueue.empty()){
        p= myqueue.front();
        myqueue.pop();
        
        if(p.first>ans.size()){
            if(ans.size()%2 ){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
            temp.clear();
            temp.push_back(p.second->val);
        }else{
            temp.push_back(p.second->val);
        }
        
        if(p.second->left != NULL){
            myqueue.push({p.first+1,p.second->left});
        }
        
        if(p.second->right != NULL){
            myqueue.push({p.first+1,p.second->right});
        }
    }
    if(ans.size()%2 ){
        reverse(temp.begin(),temp.end());
    }
    ans.push_back(temp);
    return ans;
}

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return zigzag(root);
    }
};