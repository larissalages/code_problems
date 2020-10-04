#include<bits/stdc++.h>
using namespace std;

void BubSort(int a[],int n){
    cout<<"Bubble Sort: ";
    for(int i=0;i<n-1;i++){     //total N-1 paas
        int temp;
        for(int j=0;j<n-i-1;j++){   //elements to be traversed are reduced on every pass
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;}
        }
    }
}

int main(){
    int arr[]={10,-4,7,3,1,0,2,6,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    BubSort(arr,n);
    
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
