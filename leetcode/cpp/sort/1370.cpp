class Solution {
public:
    string sortString(string s) {
     vector<int> freq(26,0);
     string res;
     int flag=1;
     for(auto c: s) freq[c-'a']+=1;
     while(flag){
         flag=0;
         for(int i=0;i<26;i++){
             if(freq[i]){
                 flag=1;
                 res+=i+'a';
                 freq[i]-=1;
             }
         }
         if(!flag) break;
         flag=0;
         for(int i=25;i>=0;i--){
             if(freq[i]){
                 flag=1;
                 res+=i+'a';
                 freq[i]-=1;
             }
         }
     }
     return res;
    }
};