class Solution {
public:
    string reorderSpaces(string text) {
        string s="",word;
        vector<string> words;
        int spaces=0,i=0;
        while(i<text.size()){
            if(text[i]==' '){
                spaces++;
                i++;
            }
            else{
                word="";
                while(i<text.size() && text[i]!=' '){
                    word+=text[i];
                    i++;
                }
                words.push_back(word);
            }
        }
        if(words.size()==1){
            s+=words[0];
            while(spaces){
                s+=' ';
                spaces--;
            }
            return s;
        }
        int n=spaces/(words.size()-1);
        for(auto word: words){
            s+=word;
            int temp=n;
            if(spaces<n) break;
            while(temp){
                s+=' ';
                temp--;
            }
            spaces-=n;
        }
        while(spaces){
            s+=' ';
            spaces--;
        }
        return s;
    }
};