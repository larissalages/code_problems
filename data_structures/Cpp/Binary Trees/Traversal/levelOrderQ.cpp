#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node* left, *right;
};

node* newNode(int data){
  node* Node=new node();
  Node->data=data;
  Node->left=NULL;
  Node->right=NULL;
  return Node;
}

void printLevelOrder(node *root){
  if(root==NULL)
    return;
  queue<node *> q;
  q.push(root);
  while(q.empty()==false){
    node *Node=q.front();
    cout<<Node->data<<" ";
    q.pop();
    if(Node->left!=NULL)
      q.push(Node->left);
    if(Node->right!=NULL)
      q.push(Node->right);
  }
  
}

int main(){
  node* root=newNode(1);
  root->left=newNode(2);
  root->right=newNode(3);
  root->left->left=newNode(4);
  root->left->right=newNode(5);

  printLevelOrder(root);
  return 0;
}

/*
      1
    /   \
   2     3
  /  \
  4   5
  Time complexity: O(n)
  Space complexity: O(n) 
*/
