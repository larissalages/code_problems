class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> s;
        int i=0;
        for( ;i<num.length(); i++) {
            char c=  num[i];
            while(k && !s.empty() && s.top() > c){
                s.pop();
                k--;
            }
            if (k==0) {
                break;
            } else if (s.empty() || s.top() <= c) {
                s.push(c);
            }
        }
        if (k==0) {
            for( ;i<num.length(); i++) {
                s.push(num[i]);
            }
        } else {
            while(k--) {
                s.pop();
            }
        }
        string str(s.size(), ' ');
        for(int j=str.size()-1; j>=0; j--){
            str[j] = s.top(); s.pop();
        }
        
        int lz = findLastZeroIdx(str);
        switch (lz) {
            case -2:
                return "0";
            default:
                return str.substr(lz+1);
        }
    }
    int findLastZeroIdx(string str) {
        for(int i=0;i<str.length(); i++) {
            if (str[i] != '0') {
                return i-1;
            }
        }
        return -2;
    }
};