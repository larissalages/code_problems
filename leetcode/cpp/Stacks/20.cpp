class Solution {
    bool checkingOpen(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
    }
    char checkBracket(char ch){
        if(ch == ']') return '[';
        else if(ch == '}') return '{';
        else return '(';
    }
public:
    bool isValid(string s) {
        stack <char> st;
       for(int i = 0 ; i < s.length() ; i++){
           if(checkingOpen(s[i])) st.push(s[i]);
           else{
              if(st.empty()) return false;
              if(checkBracket(s[i]) == st.top()) st.pop();
              else return false;
           }
       } 
        if(st.empty()) return true;
        else return false;
    }
};