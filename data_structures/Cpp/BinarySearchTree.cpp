#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data; 
	Node* left;
	Node* right;
};

Node* root=NULL;

//return pointer to newly created node
Node* MakeNode(int x){
	Node* newNode=new Node();
	newNode->data=x;
	newNode->left=newNode->right=NULL;
	return newNode;
}

//for inserting value in BST and will return address of root note
Node* Insert(Node* root,int data){
	if(root==NULL)
		root=MakeNode(data);
	//if value is lesser than root insert at left.
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	//else insert at right
	else
		root->right = Insert(root->right,data);

	return root;
}
//For searching the element return the T/F value
bool Search(Node* root,int data){
	if(root==NULL)
		return false;
	else if(root->data==data)
		return true;
	else if(data<=root->data)
		return Search(root->left,data);
	else
		return Search(root->right,data);
}
int main(){
	root=Insert(root,63);	
	root=Insert(root,11);	
	root=Insert(root,43);
	root=Insert(root,52);
	root=Insert(root,19);
	root=Insert(root,17);
 
	int key;
	cout<<"Enter value to be searched:"<<endl;
	cin>>key;
	
	if(Search(root,key)) 
		cout<<"Found!"<<endl;

	else cout<<"Not Found!"<<endl;
}
