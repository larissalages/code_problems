#include <bits/stdc++.h>

using namespace std;
 
//Bucket sort is an effiicent way of sorting numbers between 0.0 and 1.0.

//Algorithm:
void bucketSort(float array[], int n){
    vector<float> bucket[n];
    int k = 0;

    for(int i = 0; i < n; i++){
        int x = n*array[i];
        bucket[x].push_back(array[i]);
    }

    for(int i = 0; i < n; i++){
        sort(bucket[i].begin(), bucket[i].end());

    }

    for(int i = 0; i < n; i++){
        for (int j = 0; j < bucket[i].size(); j++){
            array[k] = bucket[i][j];
            k++;
        }
    }
}

//Test:
int main(){
    int n;
    float array[] = {0.182, 0.429, 0.18, 0.02, 0.912, 0.586, 0.129, 0.911};
    n = sizeof(array) / sizeof(array[0]);
    cout << "Elements before bucket sort:\n";
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << "\n";

    bucketSort(array, n);
    
    cout << "Elements after bucket sort:\n";
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}