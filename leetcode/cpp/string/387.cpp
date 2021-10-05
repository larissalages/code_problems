//387. First Unique Character in a String 
/*Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.*/


/*
Example 1:

Input: s = "leetcode"
Output: 0

Example 2:

Input: s = "loveleetcode"
Output: 2
*/

//Brute force solution, traverse string s 2 times. First time, store counts of every character into the hash table, second time, find the first character that appears only once.
class Solution {
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char, int> mpp;
        for (auto &i : s) 
        {
            mpp[i]++;
        }
        for (int i = 0; i < s.size(); i++) 
        {
            if (mpp[s[i]] == 1) 
                return i;
        }
        return -1;
    }
};

// This code is contributed by DvnOshin.
