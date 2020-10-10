import java.util.*;
class Node {
	int data;
	Node left,right;
	public Node(int val){
		data = val;
		left = right = null;
	}
}
class Traversals {
	Node root;
	Traversals(){
		root = null;
	}
	void postorder(Node node){
		if(node == null) return;
		
		postorder(node.left);
		postorder(node.right);
		System.out.print(node.data + " ");
	}
	void preorder(Node node){
		if(node == null) return;
		
		System.out.print(node.data+ " ");
		preorder(node.left);
		preorder(node.right);
		
	}
	void inorder(Node node){
		if(node == null) return;
		
		inorder(node.left);
		System.out.print(node.data + " " );
		inorder(node.right);
	}
	
	void inorder(){ inorder(root); }
	void preorder(){ preorder(root); }
	void postorder(){ postorder(root); }
	
	public static void main(String args[]){
		Traversals tree = new Traversals();
		tree.root = new Node(1);
		tree.root.left = new Node(2);
		tree.root.right = new Node(3);
		tree.root.left.left = new Node(4);
		tree.root.left.right = new Node(5);
		
		System.out.println("inorder traversal" );
		tree.inorder();
		System.out.println("preorder traversal " );
		tree.preorder();
		System.out.println(" postorder traversal" );
		tree.postorder();

	}
}

