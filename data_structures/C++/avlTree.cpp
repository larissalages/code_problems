#include <iostream>

int max(int a, int b){
    return (a > b) ? a : b;
}

struct Node{
private:
    int value;
    Node *left;
    Node *right;
    int height;
    int count;

public:
    Node(){
        left = right = NULL;
        height = 1;
        count = 1;
    }

    Node(int val, Node* l = NULL, Node* r = NULL){
        value = val;
        left = l;
        right = r;
        height = 1;
        count = 1;
    }

    int getValue(){
        return value;
    }

    void setValue(const int& v){
        value = v;
    }

    Node* getLeft(){
        return left;
    }

    void setLeft(Node *temp){
        left = temp;
    }

    Node* getRight(){
        return right;
    }

    void setRight(Node *temp){
        right = temp;
    }

    int getHeight(){
        return height;
    }

    void setHeight(int hgt){
        height = hgt;
    }

    int getCount(){
        return count;
    }

    void setCount(int cnt){
        count = cnt;
    }
};

class BST{
private:
    Node *root;
    int nodeCount;

    void clearHelp(Node*);
    Node* insertHelp(Node*, const int&);
    bool findHelp(Node*, int);

public:
    BST(){
        root = NULL;
    }

    ~BST(){
        clearHelp(root);
    }

    int height(Node *node){
        if(node == NULL){
            return 0;
        }
        return node->getHeight();
    }

    int getNodeCount(Node *node){
        if(node == NULL){
            return 0;
        }
        return node->getCount();
    }

    int getBalance(Node *node){
        if(node == NULL){
            return 0;
        }
        return height(node->getLeft()) - height(node->getRight());
    }

    Node *rightRotate(Node *node){
        Node *l = node->getLeft();
        Node *lRight = l->getRight();

        l->setRight(node);
        node->setLeft(lRight);

        node->setHeight(1 + max(height(node->getLeft()), height(node->getRight())));
        l->setHeight(1 + max(height(l->getLeft()), height(l->getRight())));

        node->setCount(1 + getNodeCount(node->getLeft()) + getNodeCount(node->getRight()));
        l->setCount(1 + getNodeCount(l->getLeft()) + getNodeCount(l->getRight()));

        return l;
    }

    Node *leftRotate(Node *node){
        Node *r = node->getRight();
        Node *rLeft = r->getLeft();

        r->setLeft(node);
        node->setRight(rLeft);

        node->setHeight(1 + max(height(node->getLeft()), height(node->getRight())));
        r->setHeight(1 + max(height(r->getLeft()), height(r->getRight())));
    
        node->setCount(1 + getNodeCount(node->getLeft()) + getNodeCount(node->getRight()));
        r->setCount(1 + getNodeCount(r->getLeft()) + getNodeCount(r->getRight()));

        return r;
    }

    void insert(const int& val){
        root = insertHelp(root, val);
    }

    bool find(int value){
        if(root == NULL){
            return 0;
        }
        nodeCount = 0;
        return findHelp(root, value);
    }

    void clear(){
        clearHelp(root);
        root = NULL;
    }
};

Node* BST::insertHelp(Node* node, const int& val){
    if(node == NULL){
        return new Node(val, NULL, NULL);
    }
    else if(val < node->getValue()){
        node->setLeft(insertHelp(node->getLeft(), val));
    }
    else if(val > node->getValue()){
        node->setRight(insertHelp(node->getRight(), val));
    }

    node->setHeight(1 + max(height(node->getLeft()), height(node->getRight())));
    node->setCount(1 + getNodeCount(node->getLeft()) + getNodeCount(node->getRight()));

    int balance = getBalance(node);

    if(balance > 1 && val < node->getLeft()->getValue()){
        return rightRotate(node);
    }
    if(balance < -1 && val > node->getRight()->getValue()){
        return leftRotate(node);
    }
    if(balance > 1 && val > node->getLeft()->getValue()){
        node->setLeft(leftRotate(node->getLeft()));
        return rightRotate(node);
    }
    if(balance < -1 && val < node->getRight()->getValue()){
        node->setRight(rightRotate(node->getRight()));
        return leftRotate(node);
    }

    return node;
}

bool BST::findHelp(Node* node, int val){
    if(node == NULL){
        return false;
    }
    if(val < node->getValue()){
        return findHelp(node->getLeft(), val);
    }
    else if(val > node->getValue()){
        nodeCount += (1 + getNodeCount(node->getLeft()));
        return findHelp(node->getRight(), val);
    }
    else{
        nodeCount += (1 + getNodeCount(node->getLeft()));
        std::cout << nodeCount << "\n";
        return true;
    }
}

void BST::clearHelp(Node* node){
    if(node == NULL){
        return;
    }
    clearHelp(node->getLeft());
    clearHelp(node->getRight());
    delete node;
}

//Simple application of AVL tree: inserting a number and searching a number in the tree. 
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    BST* avlTree = new BST;

    int operation = 1, value;

    //Operation 0 ends the program, 1 inserts an element and 2 searches a number.
    while(operation != 0){
        std::cin >> operation >> value;
        if(operation == 1){
            avlTree->insert(value);
        }
        else if(operation == 2){
            if(avlTree->find(value)){
            }
            else{
                std::cout << "Data not found\n";
            }
        }
    }

    delete avlTree;
}