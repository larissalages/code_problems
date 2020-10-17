class Solution {
public:
    int binarySearchHelper(vector<int> &nums, int lo, int hi, int target){
        //simple binary search
        int mid;
        while(lo<=hi){
            mid= lo + (hi-lo)/2;
            if (nums[mid]==target)
                return mid;
            else if (nums[mid]>target){
                hi= mid-1;
            }
            else
                lo= mid +1;
        }
        return -1;
    }


    // using the binary search predicate framework: more info at https://www.topcoder.com/community/competitive-programming/tutorials/binary-search/
    int search(vector<int>& nums, int target) {
        int n= nums.size(), lo= 0, hi= n-1, mid;
        int resIdx=-1;//final result index

        if (n==0) return -1;


        //find the minimum of the input array using, the predicate
        //P(x): A[x]<=A[0] 
        //3 4 5 1 2
        //F F F T T, x=mid, thus F*T* framework and the finding the first T is the aim
        while (lo<hi){
            mid= lo+ (hi-lo)/2;
            if (nums[mid]<nums[0])
                hi= mid;
            else
                lo= mid+1;
        }
        int min= lo;
        //lo is the index of the minimum element

        //now we have 2 sorted(ascending) subarrays, thus do a binary search on each of them
        
        if (nums[lo]==target){
            return lo;
        }
        else {
            //simple binary search on nums[0:lo-1]
            resIdx= binarySearchHelper(nums, 0, min-1, target);
            if (resIdx!=-1) return resIdx;
            //not found in the first part
            resIdx= binarySearchHelper(nums, min, n-1, target);

            //binary search on nums[lo+1,n-1] second part
            
        }
        return resIdx;//target not found anywhere
    }
};


//==================================================
//Time complexity of the algorithm(asymptotically): O(log(n)), where n is the size of the input array

//Space complexity: O(1), constant