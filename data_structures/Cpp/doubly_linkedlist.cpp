#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* prev;
	Node* next;
};

Node* head=NULL;	//initially head is null;

Node* MakeNewNode(int x) {
	Node* newNode= new Node();	//new operator creates memory space
	newNode->data=x;
	newNode->prev=NULL;
	newNode->next=NULL;
	return newNode;
}

//Inserts a Node at head of doubly linked list
void InsertAtHead(int x){
	Node* newNode=MakeNewNode(x);
	if(head == NULL){
		head = newNode;
		return;
	}
	head->prev=newNode;
	newNode->next=head; 
	head=newNode;
}

void InsertAtTail(int x){
	 Node* temp=head;
	 Node* newNode=MakeNewNode(x);
	if(head==NULL){
		head=newNode;
		return;
	}
	while(temp->next!=NULL) 
		temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

//prints all nodes starting from head till we find NULL
void Print(){
	 Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

//prints all nodes from last to head;
void ReversePrint(){
	Node* temp=head;
	if(temp==NULL) 
		return;

	//going till we reach last 
	while(temp->next!=NULL){
		temp=temp->next;
	}
	//now from last we go backwards
	while(temp!=NULL) {
		cout<<temp->data<<" ";
		temp=temp->prev;
	}
	cout<<endl;
}

int main(){
	InsertAtTail(2); 
	Print();
	InsertAtTail(4); 
	Print();
	InsertAtHead(6); 
	Print();
	InsertAtTail(8); 
	Print();
	InsertAtTail(3); 
	Print();
	InsertAtTail(1); 
	Print();
	InsertAtHead(4);
	Print();
	ReversePrint();

	return 0;
}