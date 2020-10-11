class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i1=0,i2=0;
        while(i1<v1.length() && i2<v2.length()) {
            int n1=-1, n2=-1;
            
            int p1 = (int)v1.find('.', i1);
            if (p1!=string::npos) {
                n1 = stoi(v1.substr(i1, p1-i1));
                i1 = p1+1;
            }
            else {
                n1 = stoi(v1.substr(i1));
                i1 = v1.length();
            }
            
            int p2 = (int)v2.find('.', i2);
            if (p2!=string::npos) {
                n2 = stoi(v2.substr(i2, p2-i2));
                i2 = p2+1;
            }
            else {
                n2 = stoi(v2.substr(i2));
                i2 = v2.length();
            }
            
            if (n1!= -1 && n2!= -1) {
                if (n1>n2) return 1;
                else if (n1<n2) return -1;
            }
        }
        if (i1 == v1.length()) {
            for(; i2<v2.length(); i2++) {
                if (v2[i2] != '.' && v2[i2] != '0')
                    return -1;
            }
        }  else if (i2 == v2.length()) {
            for(; i1<v1.length(); i1++) {
                if (v1[i1] != '.' && v1[i1] != '0')
                    return 1;
            }
        }
        return 0;
        
    }
};