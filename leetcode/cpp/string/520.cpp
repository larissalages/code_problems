class Solution {
public:
    bool detectCapitalUse(string word) {
        bool upper=true,lower=true;
        if(word[0]-'A'>=0&&word[0]-'A'<26)
        {
        for(int i=1;i<word.size();i++)
        {
            if(word[i]-'a'>=0&&word[i]-'a'<26)
            {
                continue;
            }
            else{
                lower=false;
                break;
            }
        }
        for(int i=1;i<word.size();i++)
        {
            if(word[i]-'A'>=0&&word[i]-'A'<26)
            {
                continue;
            }
            else{
                upper=false;
                break;
            }
        }
        }
        else{
            upper=false;
            for(int i=1;i<word.size();i++)
        {
            if(word[i]-'a'>=0&&word[i]-'a'<26)
            {
                continue;
            }
            else{
                lower=false;
                break;
            }
        }
        }
        bool ans=upper|lower;
        return ans;
    }
};
