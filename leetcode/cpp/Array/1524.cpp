class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int a= pow(10,9)+7;
        int temp[2]= {1,0}; 
        unsigned int res= 0;
        int val= 0, n= arr.size();//temp for odd and even pair
        for (int i=0;i<n;i++){
            val= ((val+arr[i])%2 +2)%2;//compute 
            temp[val]= (temp[val]+1)%a;
        }
        res= (long long)(temp[0]%a)*(temp[1]%a)%a;
        return res;
        
    }
};


//========================================================
//Time complexity of the above algorithm(asymptotically): O(n), where n is the length of the input array

//Space complexity: O(1), constant space