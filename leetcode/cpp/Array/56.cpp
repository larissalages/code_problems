class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int i, n= intervals.size(),count= 0;
        //pre processing part, creating the interval space
        vector<pair<int,int>> intervalSpace;
        for (i=0;i<n;i++){
            //push_back the first element
            intervalSpace.push_back(make_pair(intervals[i][0],0));
            //2nd element
            intervalSpace.push_back(make_pair(intervals[i][1],1));
        }
        //so the interval space contains pairs where the first elt is the number, and the second 
        //signifies whether it is a opening or closing bracket, 0-> opening, 1->closing
        //ex: [[1,2],[3,4]]
        //intervalspace: [<1,0>,<2,1>,<3,0>,<4,1>]

        sort(intervalSpace.begin(),intervalSpace.end(),[](pair<int,int> &a, pair<int,int> &b){
            // if they are equal
            if (a.first==b.first){
                return a.second <b.second;
            }
            return a.first<b.first;
        });


        //main logic
        for (i=0;i<intervalSpace.size();i++){
            //increment part
            if (intervalSpace[i].second==0){
                count++;//count signifies the level of the interval
                if (count==1){
                    res.push_back({intervalSpace[i].first});
                }
            }
            //decrement part
            else {
                count--;
                if (count==0){
                    //just finished one interval, merge with the previous interval
                    res[res.size()-1].push_back(intervalSpace[i].first);
                }
            }
        }
        return res;
    }

};
//=============================================
//the underlying logic in the solution is:
//If we imagine the interval space marked on the number line 
//arranged in ascending order, whenever there is a merging of intervals,
// the crosses(X) increase from the base level zero to some value when there is a opening juncture
// and decreases from some value to base value zero when there is a closing juncture.
//count variable signifies the level of crosses, 1 means only 1 interval has that elt,
// 2 means 2 overlapping intervals and so on...

//1 ---3   4---5---6
//  2--3
//thus:
//XXXXXX   XXXXXXXXX  
//  XXXX  


//=============================================
//Time complexity of the above algorithm asymptotically: O(nlog(n)), because of the custom sorting

//Space complexity: O(n) for the intervalSpace vector