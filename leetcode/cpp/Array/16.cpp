class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        vector<int> sortedNums;
        copy(nums.begin(),nums.end(),back_inserter(sortedNums));
        sort(sortedNums.begin(),sortedNums.end());
        int ans,a,sum,diff,mindiff=INT_MAX,indexA,indexB,indexC;
        for(int i=0;i<sortedNums.size()-2;i++){
            indexA=i;
            a=sortedNums[indexA];
            if(indexA>0 && a==sortedNums[indexA-1]) continue;
            indexB=i+1;
            indexC=sortedNums.size()-1;
            while(indexB<indexC){
                sum=sortedNums[indexA]+sortedNums[indexB]+sortedNums[indexC];
                diff=abs(target-sum);
                if(diff==0) return sum;
                if(diff<mindiff){
                    mindiff=diff;
                    ans=sum;
                }
                if(sum<target) indexB++;
                else indexC--;
            }
        }
        return ans;
    }
};