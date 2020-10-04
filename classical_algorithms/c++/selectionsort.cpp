#include<bits/stdc++.h>
using namespace std;

void SelSort(int A[],int n){
    cout<<"Selection Sort: ";
    for(int i=0;i<n-1;i++){
        int i_min=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[i_min])
                i_min=j;
        }
        int temp=A[i_min];
        A[i_min]=A[i];
        A[i]=temp;
    }
}

int main(){
    int arr[]={10,-4,7,3,1,0,2,6,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    SelSort(arr,n);
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
