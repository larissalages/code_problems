class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>>res;
        int n=v.size();
        if(n<=1) return v;
        //vector<pair<int,int>>v(intervals.begin(),intervals.end());
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++){
            if(v[i][1]>=v[i+1][0]){
                v[i+1][0]=v[i][0];
                v[i+1][1]=max(v[i][1],v[i+1][1]);
            }
            else{
                res.push_back({v[i][0],v[i][1]});
            }
        }
        res.push_back({v[n-1][0],v[n-1][1]});
        return res;
    }
};
