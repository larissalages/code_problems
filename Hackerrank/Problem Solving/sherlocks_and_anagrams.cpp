#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    map<string,int>m;
    int n = s.length();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            string ans = "";
            for(int k=i;k<=j;k++){
                ans += s[k];
            }
            if(ans!=""){
                sort(ans.begin(),ans.end());
                m[ans]++;
            }
        }
    }
    int count = 0;
    for(auto p:m){
        if(p.second>=2){
            count+=((p.second)*(p.second-1))/2;
        }
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
