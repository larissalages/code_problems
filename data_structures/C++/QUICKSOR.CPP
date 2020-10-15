//quick sort program time complexity in average case O(nlogn)

#include<iostream>
using namespace std;
void quicksort (int[], int, int);
int main ()
{
  int a[50], n, i;
  cout<<"enter number of elemnts that u want to store:\n";
  cin>>n;
  for (i = 0; i < n; i++)
    {
      cin>>a[i];
    }
  quicksort (a, 0, n - 1);
  for (i = 0; i < n; i++)
    {
      cout<<"\t"<<a[i];
    }
 return 0;
}

void
quicksort (int a[], int low, int high)
{
  int pivot, i, j, temp;
  if (low < high)
    {
      pivot = low;
      i = low;
      j = high;
      while (i < j)
	{
	  while (a[i] <= a[pivot] && i <= high)
	    {
	      i++;
	    }
	  while (a[j] > a[pivot] && j >= low)
	    {
	      j--;
	    }
	  if (i < j)
	    {
	      temp = a[i];
	      a[i] = a[j];
	      a[j] = temp;
	    }
	}
      temp = a[j];
      a[j] = a[pivot];
      a[pivot] = temp;
      quicksort (a, low, j - 1);
      quicksort (a, j + 1, high);
    }
}
