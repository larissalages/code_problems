#include<bits/stdc++.h> 
using namespace std; 
  
//Comb sort is an improvement over bubble sort, and works by varying the gap when comparing values. It has better average time, but worst case scenario is still the same.

//Algorithm:
int nextGap(int gap){
    //Curiosity: this shrink factor for the gap (~=1.3) has been suggested as the ideal one by the original authors of this sorting algorithm, but can actually be changed.
    gap = (gap*10)/13; 
  
    if(gap < 1){
        return 1; 
    }
    return gap; 
} 
  
void combSort(int array[], int n){ 
    int gap = n; 
    //The purpose of the flag is the same as in bubble sort.
    bool flag = true; 
   
    while (gap != 1 || flag == true){ 
        gap = nextGap(gap); 
        flag = false; 
  
        for (int i = 0; i < (n - gap); i++){ 
            if(array[i] > array[i + gap]){ 
                swap(array[i], array[i + gap]); 
                flag = true; 
            } 
        } 
    } 
} 

//Test:
int main(){
    int n;
    int array[] = {3, 1, 2, 9, -21, 14, 15, 12, 13, 12};
    n = sizeof(array) / sizeof(array[0]);
    cout << "Elements before comb sort:\n";
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << "\n";

    combSort(array, n);
    
    cout << "Elements after comb sort:\n";
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}