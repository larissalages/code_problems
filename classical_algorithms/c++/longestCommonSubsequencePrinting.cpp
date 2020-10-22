#include <bits/stdc++.h>
using namespace std;

int main(){
    // take input
    string s,t;
    cin>>s>>t;

    int sLength = s.length();
    int tLength = t.length();

    // create dp table
    int dp[sLength][tLength];
    memset(dp, 0, sizeof dp);
    for(int i=0;i<sLength;i++){
        for(int j=0;j<tLength;j++){
            // if the characters are same
            if(s[i] == t[j])
                dp[i][j] = ((i>0 && j>0) ? dp[i-1][j-1] : 0) + 1;
            // if characters are not same
            // choose the largest common subsequence
            // which could be made with string s[0..i-1] and t[0..j-1]
            else
                dp[i][j] = max(((i>0) ? dp[i-1][j] : 0), ((j>0) ? dp[i][j-1] : 0));
        }
    }

    // now run a backward loop
    // from bottom right corner to the top left corner
    string answer="";
    int i = sLength-1, j = tLength-1;
    while(i>=0 && j>=0){
        // you have chosen the common character
        // thus should have come to the current cell from top left diagonal direction
        // so move in opposite direction of that
        if(dp[i][j] == (((i>0 && j>0) ? dp[i-1][j-1] : 0) + 1) && s[i] == t[j])
            answer+=s[i], i--, j--;
        else if(i>0 && j>0 && dp[i-1][j] > dp[i][j-1])
            i--;
        else if(i>0 && j>0 && dp[i-1][j] < dp[i][j-1])
            j--;
        else{
            if(i>j)i--;
            else j--;
        }
    }
    reverse(answer.begin(), answer.end());
    cout<<answer;
}
