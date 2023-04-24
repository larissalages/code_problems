class Solution {
public:
    int threeSumClosest(vector<int>& A, int target) {
     sort(A.begin(),A.end());
    int f,s,t;
    int res=0;
    int min_diff =INT_MAX;
    for(f=0;f<A.size()-2;f++)
    {
        s= f+1;
        t=A.size()-1;
        while(s<t)
        { int sum= A.at(f) + A.at(s) + A.at(t);
          int cur = fabs(sum-target);
          if(cur<min_diff)
          {
              min_diff =cur;
              res =sum;
          }
          if(sum>target)
           t--;
           else if(sum<target)
           s++;
           else
           return sum;

        }
    }
    return res;
    }
};
