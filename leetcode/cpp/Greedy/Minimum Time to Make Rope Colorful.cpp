#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/*

Leetcode Problem link : https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
Problem Describtion (in short):

we have two choices, and we want the minimum balloon to pop
we popped the min so make sure that the other balloon has a choice to be popped next iteration
we do this by swapping the min and the other balloon if need be

*/

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {

        int n = neededTime.size();
        int add = 0;
        for (int i = 0; i < colors.length(); i++)
        {
            if (colors[i] == colors[i + 1])
            {
                int low = min(neededTime[i], neededTime[i + 1]);

                // lets take an example in which we have find minimum in 'b b b b ' = 8 3 4 5
                // then we will take minmum as i.e. 3 from (8,3) then swap it because we have 8 at 'i' th position

                if (neededTime[i] > neededTime[i + 1])

                    // and 3 is at 'i+1' th position then after swappinng we have (8,4) and noe we will find minimum in it
                    // try to think like we are using swap to pop out 3 from ( bbbb = 8 3 4 5 ) example

                    swap(neededTime[i], neededTime[i + 1]);

                add += low;
            }
        }

        return add;
    }
};

int main()
{

    int n;
    cin >> n;
    string colors;
    cin >> colors;

    vector<int> neededTime(n);
    for (int i = 0; i < n; i++)
    {
        cin >> neededTime[i];
    }
    int add = Solution().minCost(colors, neededTime);

    cout << add;
}

/*

Input: colors = "abaac", neededTime = [1,2,3,4,5]
Output: 3

*/
