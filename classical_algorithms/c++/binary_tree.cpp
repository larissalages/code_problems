#include <iostream> 
#include<bits/stdc++.h>
using namespace std; 

struct Node { 
	int data; 
	struct Node* left; 
	struct Node* right; 

	// val is the key or the value that 
	// has to be added to the data part 
	Node(int val) 
	{ 
		data = val; 

		// Left and right child for node 
		// will be initialized to null 
		left = NULL; 
		right = NULL; 
	} 
}; 
/*Function which print level order of the given tree*/ 
void level_order(Node* root)
{
   if(root==NULL)
   { 
       return;
   }
   queue<Node*> q;
   q.push(root);
   while(!q.empty())
   {
       Node* temp=q.front();
       cout<<temp->data<<" ";
       q.pop();
       if(temp->left!=NULL)
       {
           q.push(temp->left);
       }
       if(temp->right!=NULL)
       {
           q.push(temp->right);
       }
   }
   cout<<endl;
}
pair<Node*,int> last_node(Node* root)
{
   if(root==NULL)
   { 
       return make_pair(root,0);
   }
   queue<Node*> q;
   q.push(root);
   Node* last_parent=NULL;
   int last_value;
   while(!q.empty())
   {
       Node* temp=q.front();
       /*store the parent of last node*/
       if((temp->left!=NULL)&&(temp->right!=NULL))//if left and right sub tree are present;
       {
           if(temp->left->left==NULL&&temp->left->right==NULL&&temp->right->left==NULL&&temp->right->right==NULL)
           {
              last_parent=temp;
           }
       }
       if(temp->left!=NULL)//if left subtree only present;
       {
           if(temp->left->left==NULL&&temp->left->right==NULL)
           {
              last_parent=temp;
           }
       }
       if(temp->right!=NULL)//if right subtree only present;
       {
           if(temp->right->left==NULL&&temp->right->right==NULL)
           {
              last_parent=temp;
           }
       }
       
       /*for storing the value of last node.*/
       last_value=temp->data;
       q.pop();
       if(temp->left!=NULL)
       {
           q.push(temp->left);
       }
       if(temp->right!=NULL)
       {
           q.push(temp->right);
       }
   }
   /*return the parent of last node and the data of the last node*/
   return make_pair(last_parent,last_value);
}
void delete_node(Node* root,int value,int last_value)
{
    /*if only one node is present and we want to delete it*/
    if(root->left==NULL&&root->right==NULL)
    {
        root=NULL;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        /*if we find the node which we want to delete then change the data with last node data*/
        if(temp->data==value)
        {
            temp->data=last_value;
        }
        if(temp->left!=NULL)
        {
           q.push(temp->left); 
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
}

int main() 
{ 
     
	/*create root*/
	struct Node* root = new Node(1); 
	/* following is the tree after above statement 
			1 
			/ \ 
			NULL NULL 
	*/
    
	root->left = new Node(2); 
	root->right = new Node(3); 
	/* 2 and 3 become left and right children of 1 
					1 
					/ \ 
				2	 3 
				/ \ / \ 
			NULL NULL NULL NULL 
	*/

	root->left->left = new Node(4); 
	/* 4 becomes left child of 2 
			1 
			/ \ 
			2	 3 
			/ \ / \ 
	4 NULL NULL NULL 
	/ \ 
	NULL NULL 
	*/
	cout<<"Level order traversal before Deletion of node: ";
    level_order(root);
    
    int value;
    cout<<"Enter the value of node to be deleted"<<endl;
    cin>>value;//input the data of node which we want to delete;
    
    /*Find the last node and its parent to remove last node from tree.*/
    pair<Node*,int> last=last_node(root);
    /*remove last node*/
    if(last.first->left!=NULL&&last.first->left->data==last.second)
    {
        last.first->left=NULL;
    }
    if(last.first->right!=NULL&&last.first->right->data==last.second)
    {
        last.first->right=NULL;
    }
    /*delete the node*/
    delete_node(root, value,last.second);
    cout<<"Level order traversal after Deletion of node: ";
    level_order(root);
    
	return 0; 
} 

