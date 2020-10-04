/*
Problem Description:

Given a list of non-negative integers nums, arrange them such that they form the largest number.
Note: The result may be very large, so you need to return a string instead of an integer.

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"

*/

bool compare(string a, string b)
{
    return a+b > b+a;
}
class Solution {
public:
   
    string largestNumber(vector<int>& nums) {
        string ans="";
        vector<string>v;
        for(auto x :nums)
        {
            v.push_back(to_string(x));
        }
        sort(v.begin(), v.end(), compare); 
        for(auto x :v)
        {
            ans=ans+x;
        }
        if(ans[0]=='0')
        {
            return "0";
        }
        return ans;
    }
};
