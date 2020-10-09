class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) {
            vector<int> v;
            return v;
        }
        
        unordered_map<char,int> t , m ;
        for(char c : p) {
            t[c]++;
        }
        for(int i=0;i<p.length();i++){
            m[s[i]]++;
        }
        
        vector<int> ans;
        int st=0, en=p.length()-1;
        while(en<s.length()) {
            if (same(m,t)) {
                ans.push_back(st);
            }
            acq(m, st, en, s);
            rel(m, st, en, s);
        }
        //
        return ans;
    }
    void acq(unordered_map<char,int> & m, int &st, int &en, string &str) {
        en++;
        if (en<str.length()) {
            m[str[en]]++;
        }
    }
    void rel(unordered_map<char,int> & m, int &st, int &en, string &str) {
        m[str[st]]--;
        if (m[str[st]]==0) m.erase(str[st]);
        st++;
    }
    bool same(unordered_map<char,int> & m, unordered_map<char,int> & t) {
        for(auto p : t) {
            if (m[p.first] != p.second) 
                return false;
        }
        return true;
    }
};