#include<bits/stdc++.h>
using namespace std;

void InsSort(int arr[],int n){
    cout<<"Insertion Sort: ";
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=key;
    }
}

int main(){
    int arr[]={10,-4,7,3,1,0,2,6,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    Insort(arr,n);
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
