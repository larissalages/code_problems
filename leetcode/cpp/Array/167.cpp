class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i,j, n= numbers.size();
        vector<int> res(2,-1);
        i=0;j=n-1;
        while (i<j){
            //sum equal
            if (numbers[i]+numbers[j]==target){
                res[0]=i+1;res[1]=j+1;
                return res;
            }
            else if (numbers[i]+numbers[j]>target)
                    j--;
            else
                i++;
        }
        return res;
    }
};

//==============================================================
//Time complexity of the above algorith: O(n), n is the length of the input array

//Space complexity: O(1), constant space