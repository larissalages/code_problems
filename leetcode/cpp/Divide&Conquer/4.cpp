class Solution {
public:
    int findpos(vector<int> &x,int target){
        int m=x.size(),left=0,right=x.size(),pos;
        while(left<right){
            pos=(int)(left+right)/2;
            if(target>=x[pos]){
                if(pos<m-1){
                    if(target<=x[pos+1]) break;
                }else{
                    break;
                }
            }
            if(x[pos]<target) left=pos+1;
            else right=pos-1;
        }
        return pos;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        unsigned int pos=0;
        if(m && n) pos=findpos(nums1,nums2[0]);
        if(pos) pos-=1;
        int i=pos,j=0;
        vector<int> v;
        if(!m) v=nums1;
        else if(!n) v=nums2;
        else v.insert(v.end(),nums1.begin(),nums1.begin()+i);
        while(true){
            if(i==m){
             v.insert(v.end(),nums2.begin()+j,nums2.end());
             break;
            }
            if(j==n){
                v.insert(v.end(),nums1.begin()+i,nums1.end());
                break;
            }
            if(nums1[i]<=nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        int size=v.size();
        int mid=(int)size/2;
        if(size%2){
            return v[mid];
        }
        return (v[mid]+v[mid-1])/2.0;
    }
};