//Given an array of intergers. Find the contiguous sub-array with maximum sum.

#include <bits/stdc++.h>
using namespace std;

int main() {
        cout<<"Enter the number of elements for array:\n";
	    int n;
	    cin>>n;

	    vector<int>v(n);
	    cout<<"Enter the values of the array:\n";
        for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    int ans = INT_MIN;
	    int sum = 0;
	    for(int i=0;i<n;i++){
	        sum = max(v[i], sum + v[i]);
	        ans = max(ans, sum);
	    }

        cout<<"The maximum sum of contigous array is: ";
	    cout<<ans<<"\n";
	return 0;
}