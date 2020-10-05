class Solution {
public:
    void merge(vector<vector<int>>& intervals,int l,int mid,int r){
        int n1=mid-l+1,n2=r-mid,i,j,k=l;
        vector<vector<int>> v1,v2;
        for(i=0;i<n1;i++) v1.push_back(intervals[l+i]);
        for(j=0;j<n2;j++) v2.push_back(intervals[mid+j+1]);
        i=j=0;
        while(i<n1 && j<n2){
            if(*v1[i].begin()==*v2[j].begin()){
                if(*v1[i].rbegin()<=*v2[j].rbegin()){
                    intervals[k]=v1[i];
                    i++;
                }else{
                    intervals[k]=v2[j];
                    j++;
                }
            }
            else if(*v1[i].begin()<*v2[j].begin()){
                intervals[k]=v1[i];
                i++;
            }else{
                intervals[k]=v2[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            intervals[k]=v1[i];
            i++;
            k++;
        }
        while(j<n2){
            intervals[k]=v2[j];
            j++;
            k++;
        }
    }
    
    void mergeSort(vector<vector<int>>& intervals,int l,int r){
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(intervals,l,mid);
            mergeSort(intervals,mid+1,r);
            merge(intervals,l,mid,r);
        }
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      int i=0,curr,j,size=intervals.size();
      vector<vector<int>> v;
      vector<int> temp(2,0);
      mergeSort(intervals,0,size-1);
      while(i<size){
          curr=i;
          j=i+1;
          int maxend=*intervals[curr].rbegin();
          while(j<size && maxend>=*intervals[j].begin()){
              if(*intervals[j].rbegin()>maxend) maxend=*intervals[j].rbegin();
              curr+=1;
              j+=1;
          }
          temp[0]=*intervals[i].begin();
          temp[1]=maxend;
          v.push_back(temp);
          i=j;
      }
      return v;
    }
};

//method 2: faster than method 1
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> mp;
        for (auto &i : intervals) {
            mp[i[0] << 1]++;
            mp[(i[1] << 1) + 1]--;
        }
        int overlaps = 0, start;
        vector<vector<int>> res;
        for (auto &it : mp) {
            if (!overlaps && it.second > 0) start = it.first >> 1;
            overlaps += it.second;
            if (!overlaps && it.second < 0) res.push_back({start, (it.first - 1) >> 1});
        }
        return res;
    }
};