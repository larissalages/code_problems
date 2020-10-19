#include <bits/stdc++.h>

using namespace std; 

// Cycle sort is an optimal sorting algorithm regarding the number of memory memWrite to sort.

// Algorithm:
void cycleSort(int array[], int n){ 
    int memWrite = 0; 

    for(int cycle = 0; cycle <= n - 2; cycle++){ 
        int start = array[cycle]; 
        int pos = cycle; 

        for(int i = (cycle + 1); i < n; i++){
            if (array[i] < start){
                pos++; 
            }
        }

        if (pos == cycle){
            continue; 
        }

        while (start == array[pos]){
            pos += 1; 
        }

        if (pos != cycle){ 
            swap(start, array[pos]); 
            memWrite++; 
        } 

        while(pos != cycle){ 
            pos = cycle; 

            for(int i = cycle + 1; i < n; i++){
                if (array[i] < start){
                    pos += 1; 
                }
            }

            while(start == array[pos]){
                pos += 1; 
            }

            if(start != array[pos]){ 
                swap(start, array[pos]); 
                memWrite++; 
            } 
        } 
    } 
} 

// Test:
int main(){ 
    int array[] = {5, 1, 9, 2, 91, 23, 519, 43, 19, 3, 4, 3, 10}; 
    int n = sizeof(array) / sizeof(array[0]); 
    cout << "Elements before cycle sort:\n";
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << "\n";

    cycleSort(array, n); 

    cout << "Elements after cycle sort:\n";
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}