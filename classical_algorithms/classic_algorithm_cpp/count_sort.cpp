#include<iostream>
using namespace std;
int main()
{

	int n;
    cout<<"enter the size of array = ";
	cin>>n;

	int a[n];
	int b[n];
    cout<<"enter the array elements = ";
	for(int i=0;i<n;i++)
		cin>>a[i];

	int max = a[0];

	for(int i=0;i<n;i++)
		if(a[i]>max)
			max=a[i];

		int csum[max+1];

		for(int i=0;i<max+1;i++)
			csum[i] = 0;

		for(int i=0;i<n;i++)
			csum[a[i]]++;

		for(int i=1;i<max+1;i++)
			csum[i] += csum[i-1];

		for(int i=n-1;i>=0;i--)
		{

			csum[a[i]] = csum[a[i]] - 1;
			b[csum[a[i]]] = a[i];
		}
        cout<<"the sorted elements are = ";
		for(int i=0;i<n;i++)
			cout<<b[i]<<" ";





		return 0;
	}