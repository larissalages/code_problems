#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

// Complete the substrings function below.
int substrings(string s) {
    
    long long lastValue = s[0]-'0';
    long long totalSum = s[0] - '0';
    for(int i=1;i<s.length();i++){
        lastValue = (lastValue*10) + ((s[i]-'0')*(i+1));
        lastValue = lastValue%MOD;
        totalSum = (totalSum + lastValue)%MOD;
    }
    return totalSum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
