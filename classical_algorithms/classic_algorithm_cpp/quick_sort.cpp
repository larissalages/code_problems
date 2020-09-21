#include<iostream>
using namespace std;

void quick_sort(int[],int,int);

int partition(int[],int,int);

void quick_sort(int a[],int start,int end)
{
    if(start>=end)
        return;
    int pindex=partition(a,start,end);
    quick_sort(a,start,pindex-1);
    quick_sort(a,pindex+1,end);
 
}

int partition(int a[],int start,int end)
{
    int pivot,pindex,temp;
    pivot=a[end];
    pindex=start;
    for(int i=start;i<=end-1;i++)
        if(a[i]<=pivot)
        {
          temp=a[i];
          a[i]=a[pindex];
          a[pindex]=temp;
          pindex=pindex+1;
        }
    temp=a[pindex];
    a[pindex]=a[end];
    a[end]=temp;
    return pindex;
}
int main()
{
int n;
  int a[n] = {0};
  cout<<"enter the size of the array = ";
  cin>>n;
  cout<<"enter all the array element to sort them = ";
   for(int i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }

  quick_sort(a,0,n-1);
cout<<"Sorted elements are =  ";
for(int i=0;i<n;i++)
   cout<<a[i]<<" ";


    return 0;

}