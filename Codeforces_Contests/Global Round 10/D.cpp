// nb_9960
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        int ans = 0,i=1,c=0,j;
        for(;i<n;i++){
            if(s[i] == s[i-1]);
            else break;
        }
        s=s+s+s;
        for(j = i;j<i+n;j++){
            if(s[j] == s[j-1] && s[j] == s[j+1])
                c++;
            else{
                ans+=ceil(c/3.0);
                c = 0;
            }
        }
        cout<<ans + ceil(c/3.0)<<endl;
    }
}