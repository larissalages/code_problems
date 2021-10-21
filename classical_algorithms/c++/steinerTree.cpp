#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll INF = 1e18 + 5;

int n, k;                 //k = number of terminal nodes
ll dist[MAXK][MAXN*MAXN];

void floyd(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    cin >> n >> k;

    floyd();

    //Compute Steiner Trees
    vector<vector<ll> > minDist(1 << k, vector<ll> (n, INF));

    for(int i = 0; i < k; i++) minDist[1 << i][i] = 0;

    for(int mask = 0; mask < (1 << k); mask++){
        for(int i = 0; i < n; i++){
            for(int ss = mask; ss > 0; ss = (ss - 1) & mask){   //compute all possible subtrees being joined in rooted i
                minDist[mask][i] = min(minDist[mask][i], minDist[ss][i] + minDist[mask - ss][i]);
            }
            if(minDist[mask][i] < INF){
                for(int j = 0; j < n; j++){                    //rooted in i and mask terminals nodes have been joined
                    minDist[mask][j] = min(minDist[mask][j], minDist[mask][i] + dist[i][j]);
                }
            }
        }
    }

    vector<ll> minTotal(1 << k, INF);
    for(int mask = 0; mask < (1<<k); mask++)
        for(int i = 0; i < n; i++)
            minTotal[mask] = min(minTotal[mask], minDist[mask][i]);

    cout << minTotal[(1<<k) - 1] << '\n';

    return 0;
}
