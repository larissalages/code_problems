class Solution {
public:
    int firstBadVersion(int n) {
        long long int l=1,r=n,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(isBadVersion(mid)) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};