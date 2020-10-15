//This is a code for 01 Knapsack problem.
//input for number of items, capacity of the bag (total weight the bag can take).
//Input for values of each items and their weights.
//Output is maximum possible value the bag can take.
#include <bits/stdc++.h>
using namespace std;

int main() {

    int Number_of_items, Capacity;
    cout<<"Enter total number of items and capacity:\n";
	cin>>Number_of_items>>Capacity;
	    
    vector<int> values (Number_of_items+1);
	vector<int> weights (Number_of_items+1);
    values[0] = 0;
	weights[0] = 0;

    //DP array.
	vector<vector<int>> dp (Number_of_items+1, vector<int>(Capacity+1, 0));

    //Input for values
    cout<<"Enter the values of each items:\n";
	for(int i=1; i<Number_of_items+1; i++){
	    cin>>values[i];
	}

    //Input for weights of the items with respect to values.
    cout<<"Enter the values of each weights:\n";
	for(int i=1; i<Number_of_items+1; i++){
        cin>>weights[i];
    }
	    
    //Main algo for 0/1 Knapsack.
	for(int i=1; i<Number_of_items+1; i++){
	    int wnow = weights[i];
	    int vnow = values[i];
	    for(int j=1; j<Capacity+1; j++){
	        if(j < wnow){
	            dp[i][j] = dp[i-1][j];
            }
	        else{
	            dp[i][j] = max(dp[i-1][j], values[i] + dp[i-1][j - weights[i]]);
            }	            
	    }
	}

    cout<<"The maximum value the bag can store with the given capacity is: ";
    cout<<dp[Number_of_items][Capacity]<<"\n";

	return 0;
}