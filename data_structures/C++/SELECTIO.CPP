//Selection sort algorithm works with an time complexity of O(n^2)
#include<iostream>
using namespace std;
int main ()
{
  int a[50], n, i, j, min, temp;
  cout<<"enter number of elements that u want to store:\n";
  cin>>n;
  for (i = 0; i < n; i++)
    {
      cin>>a[i];
    }
  for (i = 0; i < n - 1; i++)
    {
      min = i;
      for (j = i + 1; j < n; j++)
	{
	  if (a[min] > a[j])
	    {
	      min = j;
	    }
	}
      if (min != i)
	{
	  temp = a[i];
	  a[i] = a[min];
	  a[min] = temp;
	}
    }
  for (i = 0; i < n; i++)
    {
      cout<<"\t"<<a[i];
    }
  return 0;
}
