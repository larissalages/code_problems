//naive solution:brute force
class Solution {
public:
    string convert(string s, int n) {
        bool flag=true;
        if(n==1) return s;
        int i=0,j=0;
        vector<vector<char>> list(n,vector<char>(s.size(),'0'));
        for(auto elem: s){
            list[i][j]=elem;
            if(flag) i++;
            else{
                i--;
                j++;
            }
            if(i==0 || i==n-1) flag=!flag;
        }
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=0;j<s.size();j++){
                if(list[i][j]!='0') ans+=list[i][j];
            }
        }
        return ans;
    }
};


class Solution{
public:
    string convert(string s,int numRows){
        if(numRows>=s.size() || numRows<=1) return s;
        string apt;
        int tie1=(numRows-1)*2,n=s.size(),tie2;
        for(int i=0;i<numRows;i++){
            con=i;
            while(con<n){
                apt.push_back(s[con]);
                if(i>0 && i<numRows-1){
                    tie2=(numRows-1-i)*2;
                    tie2+=con;
                    if(tie2<n) apt.push_back(s[tie2]);
                }
                con+=tie1;
            }
        }
        return apt;
    }
};