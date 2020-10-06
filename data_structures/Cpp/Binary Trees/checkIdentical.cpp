#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node* left, *right;
};

bool sameTree(node *tree1,node* tree2){
  if(tree1==NULL && tree2==NULL){
    return 1;
  }
  if(tree1!=NULL && tree2!=NULL){
    return(tree1->data==tree2->data && sameTree(tree1->left, tree2->left) && sameTree(tree1->right,tree2->right));
  }
  return 0;
}

node* newNode(int data){
  node* Node=new node();
  Node->data=data;
  Node->left=NULL;
  Node->right=NULL;
  return Node;
}

int main(){
  node* root1=newNode(1);
  root1->left=newNode(2);
  root1->right=newNode(3);
  root1->left->left=newNode(4);
  root1->left->right=newNode(5);

  node* root2=newNode(1);
  root2->left=newNode(2);
  root2->right=newNode(5);
  root2->left->left=newNode(4);
  root2->left->right=newNode(5);

  if(sameTree(root1,root2)==0){
    cout<<"NOT IDENTICAL"<<endl;
  }else{
    cout<<"Identical"<<endl;
  }
  return 0;
}

/*
      1
    /   \
   2     3
  /  \
  4   5
  Time complexity: worst case: O(n^2)
  Space complexity: O(n) for worst case for skewed tree 
                    For balanced tree O(logn)
*/
