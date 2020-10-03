//kind of iterative solution
class Solution {
public:
    int digcount;
    
    long long int next(long long int x,int low){
        if(x%10==9){
            digcount+=1;
            return initial(low);
        }
        long long int power=pow(10,digcount-1);
        return (x%power)*10+(x%10+1);
    }
    
    long long int initial(int low){
        long long int digit=1;
        for(int i=2;i<=digcount;i++) digit=digit*10+i;
        while(digit<low) digit=next(digit,low);
        return digit;
    }
    
    void setDigcount(int digit){
        digcount=log10(digit);
    }
    
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        long long int x;
        setDigcount(low);
        x=initial(low);
        while(x<=high){
            if(x%10==0) break;
            v.push_back(x);
            x=next(x,low);                
        }
        return v;
    }
};

//backtracking solution(kind of same as previous one)
class Solution {
public:
    void backtrack(vector<int> &v, int low, int high, int num) {
        if (num == 9) return;
        if (num % 10 < 9) {
            num = num * 10 + (num % 10) + 1;
            if (num >= low && num <= high)
                v.push_back(num);
            
            backtrack(v, low, high, num);
        }
        else  {
            int exp = log10(num), highestDigit = num / pow(10, exp);
            backtrack(v, low, high, highestDigit + 1);
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        backtrack(v, low, high, 1);
        sort(begin(v), end(v));
        return v;
    }
};