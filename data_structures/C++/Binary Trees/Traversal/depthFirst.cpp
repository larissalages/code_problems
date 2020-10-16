#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node* left, *right;
};

void printPreorder(node *root){
  if(root==NULL)
    return;
  cout<<root->data<<" ";
  printPreorder(root->left);
  printPreorder(root->right);
}

void printInorder(node *root){
  if(root==NULL)
    return;
  printInorder(root->left);
  cout<<root->data<<" ";
  printInorder(root->right);
}

void printPostorder(node *root){
  if(root==NULL)
    return;
  printPostorder(root->left);
  printPostorder(root->right);
  cout<<root->data<<" ";
}

node* newNode(int data){
  node* Node=new node();
  Node->data=data;
  Node->left=NULL;
  Node->right=NULL;
  return Node;
}

int main(){
  node* root=newNode(1);
  root->left=newNode(2);
  root->right=newNode(3);
  root->left->left=newNode(4);
  root->left->right=newNode(5);

  // root left right
  cout<<"PreOrder: ";
  printPreorder(root);
  cout<<"\n";

  // left root right
  cout<<"InOrder: ";
  printInorder(root);
  cout<<"\n";

  // left right root
  cout<<"PostOrder: ";
  printPostorder(root);
  cout<<"\n";
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
