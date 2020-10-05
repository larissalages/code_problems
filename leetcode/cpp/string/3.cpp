class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int i=0,j=0,maxsize=0;
        set<char> longestsofar;
        while(j<s.length()){
            if(longestsofar.find(s[j])==longestsofar.end()){
                longestsofar.insert(s[j]);
                j++;
                if(longestsofar.size()>maxsize) maxsize=longestsofar.size();
            }else{
                longestsofar.erase(s[i]);
                i++;
            }
        }
        return maxsize;
    }
};