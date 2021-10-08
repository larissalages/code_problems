#include <iostream>
#include <string>

int toInt(std::string x, int sz){
    int i, sum = 0;
    for(i = 0; i < x.length(); i++){
        sum += (int)x.at(i) * (i+1);
    }
    return sum % sz;
}

int hInt(int x, int sz){
    return x % sz;
}

struct Node{
    std::string value;
    Node* next;

    //Link constructor with element value
    Node(std::string val, Node* nextVal = NULL){
        value = val;
        next = nextVal;
    }
    //Link constructor without assigned value
    Node(Node* nextVal = NULL){
        next = nextVal;
    }
};

class HashTable{
private:
    Node **arr;
    int maxSize, currSize;

public:
    HashTable(int sz = 101){
        maxSize = sz;
        currSize = 0;
        arr = new Node*[maxSize];

        for(int i = 0; i < maxSize; i++){
            arr[i] = NULL;
        }
    }

    ~HashTable(){
        for(int i = 0; i < maxSize; i++){
            delete arr[i];
        }
        delete[] arr;
    }

    void insert(std::string val){
        int key = toInt(val, maxSize);
        Node* temp = arr[key];
        Node* holdVal = new Node(val, NULL);

        if(arr[key] == NULL){
            arr[key] = holdVal;
        }
        else{
            while(temp->next){
                temp = temp->next;
            }
            if(arr[key]->value.compare(holdVal->value) != 0){
                temp->next = holdVal;
            }
        }
    }

    void print(){
        for(int i = 0; i < maxSize; i++){
            Node* temp = arr[i];
            std::cout << "arr[" << i << "]--> ";
            while(temp){
                std::cout << temp->value << " --> ";
                temp = temp->next;
            }
            std::cout << "NULL\n";
        }
    }

    int computeSize(){
        currSize = 0;
        for(int i = 0; i < maxSize; i++){
            Node* temp = arr[i];
            while(temp){
                currSize++;
                temp = temp->next;
            }
        }
        return currSize;
    }
};

int main(){
    int query, m, n, i, j, k, hashSize;
    std::string lang1[1501], lang2[1501], concat;

    std::cin >> query;

    for(i = 0; i < query; i++){
        std::cin >> m >> n;
        std::cin.ignore();

        HashTable* hashTbl = new HashTable(m*n);
        for(j = 0; j < m; j++){
            getline(std::cin, lang1[j]);
        }

        for(j = 0; j < n; j++){
            getline(std::cin, lang2[j]);
        }

        for(j = 0; j < m; j++){
            for(k = 0; k < n; k++){
                concat = lang1[j] + lang2[k];
                hashTbl->insert(concat);
            }
        }

        std::cout << "Case " << i + 1 << ": " << hashTbl->computeSize() << "\n";

        //hashTbl->print();
        delete hashTbl;
    }
}