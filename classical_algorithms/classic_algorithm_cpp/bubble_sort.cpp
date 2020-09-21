#include<iostream>
using namespace std;

void bubble_sort(int a[],int n)
{
    int temp;
   for(int i=0;i<n;i++)
     for(int j=0;j<n-i;j++)
        if(a[j]>a[j+1])
        {
         temp=a[j+1];
         a[j+1]=a[j];
         a[j]=temp;
        }
   cout<<"Sorted elements list: ";
   for(int i=0;i<n;i++)
     cout<<a[i]<<" ";
}
int main()
{
    int n;
  cout<<"enter the size of the array = ";
  cin>>n;
  int a[n] = {0};
  
  cout<<"enter all the array element to sort them = ";
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
bubble_sort(a,n);
    return 0;
}