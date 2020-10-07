class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t="";
        if(s.size()==1)
        {
     return false;
        }
    int n=s.size();
        for(int i=0;i<s.size()/2;i++)
        {
            t+=s[i];
           // cout<<t<<endl;
            int x=t.size();
            if(n%x==0)
            {
                string res;
                for(int j=0;j<n/x;j++)
                {
                res+=t;
                }
            if(res==s)
            {
              //  cout<<res;
               return true;
                
            }
            }
            
        }
        return false;
    }
};
