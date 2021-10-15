#include <iostream>
#include <string>

int h(std::string x){
    int i, sum = 0;
    for(i = 0; i < x.length(); i++){
        sum += (int)x.at(i) * (i+1);
    }
    return sum % 101;
}

int hInt(int x){
    return x % 101;
}

struct Node{
    int key;
    std::string value;

    Node(int k, std::string val){
        key = k;
        value = val;
    }
};

class hashTable{
private:
    Node **arr;
    int maxSize, currSize;
    Node *tombstone;

public:
    hashTable(){
        maxSize = 101;
        currSize = 0;
        arr = new Node*[maxSize];

        for(int i = 0; i < maxSize; i++){
            arr[i] = NULL;
        }

        tombstone = new Node(-1, "");
    }

    ~hashTable(){
        delete arr;
        delete tombstone;
    }

    void insert(int key, std::string value){
        Node* temp = new Node(key, value);
        int index = hInt(key);

        while(arr[index] != NULL && arr[index]->key == key && arr[index]->key != -1){
            index++;
            index %= maxSize;
        }

        if(arr[index] == NULL || arr[index]->key == -1){
            currSize++;
        }

        arr[index] = temp;

        delete temp;
    }

    std::string deleteNode(int key){
        int index = hInt(key);

        while(arr[index] != NULL){
            if(arr[index]->key == key){
                Node* temp = arr[index];
                arr[index] = tombstone;

                currSize--;
                return temp->value;
            }
            index++;
            index %= maxSize;
        }
        return NULL;
    }

    int sizeofHash(){
        return currSize;
    }
};

/*
Test: concatenation of languages
- Reads how many test cases there are;

For each test case:
- Reads the amount of strings from language A and B;
- Reads the strings that make language A, one per line;
- Reads the strings that make language B, one per line;
- Outputs how many different combinations there are after concatenating both languages.
*/
int main(){
    int query, m, n, i, j, k, key;
    std::string lang1[1501], lang2[1501], concat;

    std::cin >> query;

    for(i = 0; i < query; i++){
        std::cin >> m >> n;
        std::cin.ignore();
        hashTable* myHash = new hashTable;
        for(j = 0; j < m; j++){
            getline(std::cin, lang1[j]);
        }

        for(j = 0; j < n; j++){
            getline(std::cin, lang2[j]);
        }

        for(j = 0; j < m; j++){
            for(k = 0; k < n; k++){
                concat = lang1[j] + lang2[k];
                key = h(concat);
                myHash->insert(key, concat);
            }
        }

        std::cout << "Case " << i + 1 << ": " << myHash->sizeofHash() << "\n";
        delete myHash;
    }
}