#include<iostream>
using namespace std;

void selection_sort(int a[],int n)
{
    int imin,temp;
    for(int i=0;i<=n-2;i++)
    {
        imin=i;
        for(int j=i+1;j<=n-1;j++)
        {
            if(a[j]<a[imin])
                imin=j;
        }
        temp=a[imin];
        a[imin]=a[i];
        a[i]=temp;
    }
   printf("Sorted elements list: ");
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

  selection_sort(a,n);

    return 0;

}