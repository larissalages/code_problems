class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n= A.size(),j, cumSum= 0, res= 0, r;
        //key is the remainder given by the prefix sum on division with k
        //value is the count
        unordered_map<int,int> m;
        
        m[0]= 1;
        for (j=0;j<n;j++){
            cumSum+=A[j];
            
            //r2-r can be 0, k,-k
            //so r2 can be r, r+k, r-k;
            r= cumSum%K;
            res+= m[r];
            res+= m[r+K];
            res+= m[r-K];
            
            m[r]++;
        }
        return res;
        
    }
};

//===============================================================
//Time complexity of the above algorith: O(n), n is the length of the input array

//Space complexity: O(n), because of the hashmap