// Quick Sort using c++
#include <iostream>
using namespace std;

/*
Here's what is happening, 
        we are selecting an element as a pivot element, and based on that
        we are dividing the array by two parts, 1st part is having elements
        lesser and equal to(<=) the pivot element and 2nd part having elements consists 
        of larger(>) than the pivot element. After that, we simply sort the two parts 
        recursively.

        Now, the dividing part is done by the partition function and the sorting 
        part via the quickSort function.

        average time complexity- NlogN
        worst time complexity - N^2
        Approach- Divide and Conquer
*/



int partition(int *arr,int s,int e){
    int i=s-1;
    int j=s;
    int pivot=arr[e];
    for(;j<=e-1;j++){
        if(arr[j]<=pivot){
            i=i+1;
            swap(arr[i],arr[j]);            
        }
        
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}


void quickSort(int *arr,int s,int e){
    // base case
    if(s>=e){
        return;
    }
    // rec-case
    int p = partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}


int main() {
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // functin call
    quickSort(arr,0,n-1);

    cout<<"After Quick Sort: ";
    for(int i=0;i<n;i++){
        
        cout<<arr[i]<<" ";
    }
}
 