class Solution {
public:
    int numberOfSteps (int num) {
     if(num==0 || num==1) return num;
     int ans=0;
     while(num){
         num&1? num-=1: num>>=1;
         ans+=1;
     }
     return ans;
    }
};