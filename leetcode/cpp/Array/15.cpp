class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> triplets;
      if(nums.size()<3) return triplets;
      vector<int> sortedNums;
      copy(nums.begin(),nums.end(),back_inserter(sortedNums));
      sort(sortedNums.begin(),sortedNums.end());
      int indexA,indexB,indexC,a,sum;
      for(int i=0;i<sortedNums.size()-2;i++){
          indexA=i;
          a=sortedNums[indexA];
          if(a>0) return triplets;
          if(i>0 && a==sortedNums[indexA-1]) continue;
          indexB=i+1;
          indexC=sortedNums.size()-1;
          while(indexB<indexC){
              sum=sortedNums[indexA]+sortedNums[indexB]+sortedNums[indexC];
              if(sum==0){
                  triplets.push_back({a,sortedNums[indexB],sortedNums[indexC]});
                  while(indexB<indexC && sortedNums[indexB]==sortedNums[indexB+1]) indexB++;
                  while(indexC>indexB && sortedNums[indexC]==sortedNums[indexC-1]) indexC--;
                  indexB++;
                  indexC--;
              }else if(sum<0){
                  indexB++;
              }else{
                  indexC--;
              }
          }
      }
      return triplets;
    }
};