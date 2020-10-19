class Solution {
public:
    string customSortString(string S, string T) {
        sort(T.begin(),T.end(),[&S](char &a, char &b){
            if (a==b)
                return a<b;
            return S.find(a)<S.find(b);
        });
        return T;
    }
};

//================================================================
//Time complexity of the above algorithm: O(nlog(n)), where n is the length of the string T

//Space complexity: O(1)