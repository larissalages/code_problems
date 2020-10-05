#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin>>s;
        ll one = 0,zero=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                one++;
            }else{
                zero++;
            }
        }
        if(one==0 || zero == 0){
            cout<<s<<endl;
        }else{
            for(int i=0;i<s.length();i++){
                cout<<"10";
            }
            cout<<endl;
        }
    }
    return 0;
}