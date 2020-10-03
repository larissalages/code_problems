struct Node{
    int val;
    Node *next;
    Node(int x):val(x),next(NULL){};
};

class MyLinkedList {
public:
    Node *head;
    int size;
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->head=NULL;
        this->size=0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>=this->size) return -1;
        auto *headref=this->head;
        while(index){
            headref=headref->next;
            index--;
        }
        return headref->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto *temp=new Node(val);
        temp->next=this->head;
        this->head=temp;
        this->size+=1;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto *headref=this->head;
        while(headref->next) headref=headref->next;
        headref->next=new Node(val);
        this->size+=1;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>this->size) return;
        if(!index){
            this->addAtHead(val);
            return;
        }
        index-=1;
        auto *headref=this->head;
        while(index){
            headref=headref->next;
            index--;
        }
        auto *temp=new Node(val);
        temp->next=headref->next;
        headref->next=temp;
        this->size+=1;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=this->size) return;
        this->size-=1;
        if(!index){
         this->head=this->head->next;
         return;
        }
        index-=1;
        auto *headref=this->head;
        while(index){
            headref=headref->next;
            index--;
        }
        auto *temp=headref->next;
        headref->next=headref->next->next;
        delete temp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */