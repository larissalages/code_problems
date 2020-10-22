//Min heap implementation.
// This question is submitted on Hackerrank to "QHEAP1". So, it is according to it.
#include <cmath>
#include <cstdio>
#include <vector>         // Not used in this.
#include <iostream>             
#include <algorithm>    // Used for heap STL. Not used in this.
#include<climits>       // It is used to get maximum and minimum limits of different data types.
using namespace std;

void swap(int *x, int *y){      //Swap function to swap the elements of array.
    int temp=*x;
    *x=*y;
    *y=temp;
}

class MinHeap                   // Class MINHEAP
{
    int size;
    int capacity;
    int *harr;                  // Pointer to array to be made into Min heap.
public:                         
    MinHeap(int cap);           // Constrcutor which takes capacity.
    void insertkey(int k);
    void deletekey(int k);
    int getmin();              // returns minimum element or the top element from the heap.
    void Minheapify(int i);     // Recreates the heap which was disturbed due to deletion or insertion of element.

    int parent(int i){          // Returns parent node index of i. Similarly left and right functions do their works.
        return (i-1)/2;
    }

    int left(int i){
        return (2*i)+1;
    }    

    int right(int i){
        return (2*i)+2;
    }
};

MinHeap::MinHeap(int cap){      // Constructor for MinHeap.
    size=0;
    capacity=cap;
    harr=new int[cap];          // Creates array of size cap=q. new is used to get address of array in harr.
}

void MinHeap::insertkey(int k){     // Insert key in MinHeap.
    if(size==capacity){
        cout<<"Heap size is full. Couldn't insert.";
        return;
    }

    size++;
    int i=size-1;
    harr[i]=k;
    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(&harr[parent(i)],&harr[i]);
        i=parent(i);
    }
}

void MinHeap::deletekey(int k){     // Find the value(k) and delete it from the heap.
    int i,j;
    for(j=0;j<size;j++){
        if(harr[j]==k){
            i=j;
            break;
        }
    }
    if(size==1 || size-1==i){
        size--;
        return;
    }
    harr[i]=harr[size-1];
    size--;
    Minheapify(i);
}

int MinHeap::getmin(){              // Returns minimum element from the heap.
    return harr[0];
}

void MinHeap::Minheapify(int i){    // Heapify the heap to MinHeap at index i.
    int smallest=i;
    int l=left(i);
    int r=right(i);
    if(harr[smallest]>harr[l] && l<size){
        smallest=l;
    }
    if(harr[smallest]>harr[r] && r<size){
        smallest=r;
    }
    if(smallest!=i){
        swap(&harr[i],&harr[smallest]);
        Minheapify(smallest);
    }
}

int main(){
    int q;                      // Numeber of queries.
    cin>>q;
    MinHeap h(q);               // h is object of types MinHeap.
    while(q--){
        int operation, k;
        cin>>operation;
        if(operation==1){
            cin>>k;
            h.insertkey(k);
        }
        else if(operation==2){
            cin>>k;
            h.deletekey(k);
        }
        else if(operation==3){
            cout<<h.getmin()<<"\n";
        }
    }
    return 0;
}