// Author:Nishtha
#include <bits/stdc++.h> 
using namespace std; 

class node
{
public:
  int key_value;
  node* left, *right;
};

// node* newNode(int data){
//   node* Node=new node();
//   Node->data=data;
//   Node->left=NULL;
//   Node->right=NULL;
//   return Node;
// }

void insert(int key, node *leaf)
{
  if(key< leaf->key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}

// Drive Code 
int main() 
{  
  cout<<"Enter the no. of numbbers to be entered:"<<endl;
  int n;cin>>n;
  cout<<"Enter numbers:";
  node* root=NULL;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    if(root!=NULL)
    insert(x, root);
    else
    {
      root=new node;
      root->key_value=x;
      root->left=NULL;
      root->right=NULL;
    }
  }

  return 0; 
} 
