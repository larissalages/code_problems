#include<iostream>
using namespace std;

void merge(int *a,int low,int high)
{
	int mid = (low+high)/2;
	int i,j,k;
	i = low;
	j = mid+1;
	k = low;
	int b[10000] = {0};

	while(i<=mid && j<=high)
	{
	

		if(a[i] <= a[j])
		{
			b[k] = a[i];
			i++;
		}
		
		else
		{
			b[k] = a[j];
			j++;
		}
		
			k++;
	}

			while(i<=mid)
			{
				b[k] = a[i];
				i++;k++;
			}

			while(j<=high)
			{
				b[k] = a[j];
				j++;k++;
	}

	for(int i=low;i<=high;i++)
			a[i] = b[i];
}


void merge_sort(int a[],int low,int high)
{ 

			if(low<high)
			{

		int mid = (low+high)/2;

		
				merge_sort(a,low,mid);

				merge_sort(a,mid+1,high);

				merge(a,low,high);
			}
}
int main()
{
	int n;
cout<<"enter the size of array = ";
			cin>>n;

			int a[n] = {0};
cout<<"enter the array element = ";
			for(int i=0;i<n;i++)
			{
				cin>>a[i];
			}
			int low = 0,high = n-1;

			merge_sort(a,low,high);
        cout<<"The sorted elements are = ";
			for(int i=0;i<n;i++)
				cout<<a[i]<<" ";


			return 0;
		}