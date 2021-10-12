/*
1689. Partitioning Into Minimum Number Of Deci-Binary Numbers
Medium

A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.
Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

Example 1:
Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32

Example 2:
Input: n = "82734"
Output: 8

Example 3:
Input: n = "27346209830709182346"
Output: 9
*/

//basic idea is to find largest element in the string
class Solution {
public:
    int minPartitions(string n) {
        int l=n.size();             //length of dtring n
        char max='-1';
        for(int i=0; i<l; i++)
        {
            if(n[i] > max)
                max=n[i];           //find element with maximum value
            if(max=='9')
                break;
        }
        return max-'0';
    }
};
