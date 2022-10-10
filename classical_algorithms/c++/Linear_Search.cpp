#include<bits/stdc++.h>
using namespace std;
void linear_search(int x,vector<int>numbers)
{
    for(int i=0;i<numbers.size();i++)
    {
        if(numbers[i]==x)
        {
            cout<<"Number found in the array."<<endl;
            return ;
        }
    }
    cout<<"Number not found in the array."<<endl;
    return;
}
int main()
{
    vector<int>numbers = {-5,62,987,-45,6,14,-94,2,10};
    int num;
    cout<<"Enter number to be searched in the array : "<<endl;
    cin>>num;
    linear_search(num,numbers);
    return 0;
}