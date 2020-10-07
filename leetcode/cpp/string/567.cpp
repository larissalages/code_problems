class Solution {
public:
    bool checkInclusion(string sml, string lrg) {
        if (lrg.length() < sml.length())
            return false;
        
        unordered_map<char, int> targetMap, haveMap;
        for(char c: sml) {
            targetMap[c]++;
        }
        
        for(char c: lrg.substr(0, sml.length())) {
            haveMap[c]++;
        }
        
        int st=0, en=sml.length()-1;
        while(en < lrg.length()) {
            if (targetMap == haveMap) {
                return true;
            }
            
            haveMap[lrg[st]]--; 
            if (haveMap[lrg[st]]==0) haveMap.erase(lrg[st]);
            st++;
            en++; 
            if (en<lrg.length())
                haveMap[lrg[en]]++;
        }
        return false;
        
    } 
};
