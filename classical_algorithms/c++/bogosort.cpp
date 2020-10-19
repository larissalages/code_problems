#include<bits/stdc++.h> 
using namespace std; 
  
//Bogo sort (AKA slow sort,random sort, monkey sort, estou com sort) is an algorithm based on the random sorting of elements. Although it's not actually used in practice, it's a good tool to teach about more efficient algorithms.
//Heads-up note: the algorithm will certainly run for a very (very!) long time if you try to sort too many elements, 10 is already a good deal.

//Algorithm:
bool isSorted(int array[], int n){ 
    while(n-1 > 0){
        n--;
        if(array[n] < array[n-1]){
            return false; 
        }
    }
    return true; 
} 
  
void shuffle(int array[], int n){
    for(int i=0; i < n; i++){
        swap(array[i], array[rand()%n]);
    }
} 

void bogoSort(int array[], int n){ 
    while(!isSorted(array, n)){
        shuffle(array, n); 
    } 
} 

//Test:
int main(){
    int n;
    int array[] = {3, 1, 4, 5, 8, 7, 9, 2, 10, 6};
    n = sizeof(array) / sizeof(array[0]);
    cout << "Elements before bogo sort:\n";
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << "\n";

    bogoSort(array, n);
    
    cout << "Elements after bogo sort:\n";
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}