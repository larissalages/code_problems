class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        digits[n-1]+=1;
        int carry=digits[n-1]/10;
        digits[n-1]%=10;
        for(int i=n-2;i>=0;i--){
            if(carry==1){
                digits[i]+=1;
                carry=digits[i]/10;
                digits[i]%=10;
            }
        }
        if(carry==1){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
