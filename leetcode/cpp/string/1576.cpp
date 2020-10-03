class Solution {
public:
    string modifyString(string s) {
        string alphabets="abcdefghijklmnopqrstuvwxyz";
        char chr;
        for(int i=0;i<s.length();i++){
            if(s[i]=='?'){
                chr=alphabets[rand()%26];
                if(i>0 && i<s.length()-1){
                    while(chr==s[i-1] || chr==s[i+1]){
                        chr=alphabets[rand()%26];
                    }
                }else if(i>0){
                    while(chr==s[i-1]){
                        chr=alphabets[rand()%26];
                    }
                }else{
                    while(chr==s[i+1]){
                        chr=alphabets[rand()%26];
                    }
                }
                s[i]=chr;
            }
        }
        return s;
    }
};