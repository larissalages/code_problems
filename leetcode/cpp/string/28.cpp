class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;
        double needle_hash=0, hay_hash=0;
        for(int i=0;i<needle.size();++i)
        {
            needle_hash+=((needle[i]-'a')*pow(3,i));
        }
        for(int i=0;i<needle.size();++i)
        {
            hay_hash+=((haystack[i]-'a')*pow(3,i));
        }
        int k=0;
        do
        {
            if(needle_hash==hay_hash)
                return k;
            if(k+needle.size()>haystack.size())
                return -1;
            hay_hash-=(haystack[k]-'a');
            hay_hash/=3;
            hay_hash+=((haystack[k+needle.size()]-'a')*pow(3,needle.size()-1));
            k++;
        }while(1);
    }
};
