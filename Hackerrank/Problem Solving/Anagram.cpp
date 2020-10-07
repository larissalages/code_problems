//Problem Link : https://www.hackerrank.com/challenges/anagram/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) 
{
    long n=s.size(),k=0;
    string a,b;
    if(n%2==1)
    return -1;
    else
    {
        for(int i=0;i<n/2;i++)
        {
            a[i]=s[i];
        }
        for(int i=n/2;i<n;i++)
        {
            b[i]=s[i];
        }
        for(int i=n/2;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                        if(b[i]==a[j])
                            {
                                k++;
                                 a[j]='0';
                                j=n/2;
                               
                            }
            }
        }
        return (n/2-k);
    }
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

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

