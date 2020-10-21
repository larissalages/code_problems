class Solution {
public:
    void sortColors(vector<int>& A) {
        int count_0=0,count_1=0,count_2=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==0)
         count_0++;
        else if(A[i]==1)
         count_1++;
        else if(A[i]==2)
         count_2++;
    }
    for(int i=0;i<count_0;i++)
      A[i]=0;
    for(int i=count_0;i<count_0+count_1;i++)
      A[i]=1;
    for(int i=count_1+count_0;i<count_0+count_1+count_2;i++)
      A[i]=2;
    }
};
