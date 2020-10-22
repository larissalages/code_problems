class Solution {
public:
    void reverseString(vector<char>& s) {
        
        //We are traversing the string from start and end and swapping the characters.
        for(int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};
