class Solution {
public:
    
    bool static comp(string s1,string s2){
        int h1 = (s1[0]-'0')*10 + (s1[1]-'0');
        int h2 = (s2[0]-'0')*10 + (s2[1]-'0');
        if(h1!=h2){
            return h1<h2;
        }
        int m1 = (s1[3]-'0')*10 + (s1[4]-'0');
        int m2 = (s2[3]-'0')*10 + (s2[4]-'0');
        return m1<=m2;
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string,vector<string>>h;
        for(int i=0;i<keyName.size();i++){
            h[keyName[i]].push_back(keyTime[i]);
        }
        vector<string>ans;
        for(auto it=h.begin();it!=h.end();it++){
            vector<string>v = it->second;
            if(v.size()>=3){
                sort(v.begin(),v.end(),comp);
            }
            int count=1;
            int i=0,j=1;
            while(j<v.size()){
                int h1=(v[i][0]-'0')*10 + (v[i][1]-'0');
                int h2=(v[j][0]-'0')*10 + (v[j][1]-'0');
                if(h1==h2){
                    count++;
                    if(count>=3){
                        ans.push_back(it->first);
                        break;
                    }
                    j++;
                }else{
                    if(h2==h1+1){
                        int m1 = (v[i][3]-'0')*10 + (v[i][4]-'0');
                        int m2 = (v[j][3]-'0')*10 + (v[j][4]-'0');
                        if(60-m1+m2<=60){
                            count++;
                            if(count>=3){
                                ans.push_back(it->first);
                                break;
                            }
                            j++;
                        }else{
                            i++;
                            count--;
                        }
                    }else{
                        i++;
                        count--;
                    }
                }
            }
            
        }
        return ans;
        
    }
};