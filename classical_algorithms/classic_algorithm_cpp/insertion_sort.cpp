#include<iostream>
using namespace std;
int n;

void insertion_sort(int a[])
{
    int hole,value;
    for(int i=1;i<n;i++)
    {
        hole=i;
        value=a[i];
        while(a[hole-1]>value && hole>0)
        {
            a[hole]=a[hole-1];
            hole=hole-1;
        }
        a[hole]=value;
    }
   cout<<"Sorted elements list: ";
   for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
}
int main()
{
    cout<<"enter the size of the array = ";
  cin>>n;
  int a[n] = {0};
  
  cout<<"enter all the array element to sort them = ";
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   insertion_sort(a);

    return 0;
}