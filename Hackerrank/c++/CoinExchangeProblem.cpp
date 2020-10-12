#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector < long > c){
  long m=c.size();
    long count[n+1];
    memset(count, 0, sizeof(count));
     
    count[0] = 1;
     
   
    for (int i=1; i<=n; i++)
        for (int j=0; j<m; j++)
 
         
            if (i >= c[j])
                count[i] += count[i] - c[j];
        
    return count[n];    
   
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    long ways = getWays(n, c);
    return 0;
}
