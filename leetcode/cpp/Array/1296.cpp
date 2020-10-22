class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()); 
        vector<pair<int,int>> v;
        int n= nums.size();

        //filling the vector with the appropriate values
        for (int i=0;i<n;i++){
            if (i==0|| v[v.size()-1].first!= nums[i]){
                v.push_back(make_pair(nums[i],1));
            }
            else
                v[v.size()-1].second++;
        }
        
        for (int i=0;i<v.size();i++){
            if (v[i].second==0)
                continue;
            int j= i;
            
            if (j+k-1>=v.size()) return false;
            //i denotes the element pair we are at now
            for (int l=j+1;l<j+k;l++){
                //check whether the successive elements are consecutive
                if (v[l].first!=v[l-1].first+1)
                    return false;
                //the count of the present element should at least be equal to that of the ith elmt(min), in order to fill that bucket
                
                if (v[l].second<v[j].second)
                    return false;
                //if all the conditions above holds true, then we can use that element, as many as times as that of i, so decrementing
                v[l].second-= v[j].second;
            }
        }
        return true;
        
    }
};


//==============================================================================
//Time complexity of the above algorithm asymptotically: O(nlog(n)), where n is the size of the input array

//Space complexity: O(n)