#include<bits/stdc++.h>
using namespace std;
void binary_search(int x,vector<int>numbers,int low, int high)
{

    while(low<=high){
    int mid = (low+high)/2;
    if(numbers[mid]==x)
    {
        cout<<"Number found in the array."<<endl;
        return;
    }
    else if(numbers[mid]>x)
    {
        high = mid-1;
    }
    else
    {
        low=mid+1;
    }
    }
    cout<<"Number not found in the array."<<endl;
    return;
}
int main()
{
    vector<int>numbers = {-10,-6,-3,0,15,34,50,57,100};
    int num,low=0,high=numbers.size()-1;
    cout<<"Enter number to be searched in the array : "<<endl;
    cin>>num;
    binary_search(num,numbers,low,high);
    return 0;
}