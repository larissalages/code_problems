// https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>
using namespace std;

int n, c;

// method to check if we can put all cows in the stalls such that
// the minimum distance between any two cows is greater or equal to dist
bool checkDist(int dist, vector<int>& stall) {
    int atDist = stall[0];
    int atC = c-1;
    for(int i = 1; i < n; i++) {
        if(stall[i] - atDist >= dist) {
            atDist = stall[i];
            atC--;
        }
        if(atC <= 0) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int test;
    cin >> test;
    for(int t = 0; t < test; t++) {
        cin >> n >> c;

        // read input and sort vector
        vector<int> stall(n);
        for(int i = 0; i < n; i++) cin >> stall[i];
        sort(stall.begin(), stall.end());

        // binary search the answer
        int lo = 0;
        int high = 1e9+1;
        while(high - lo > 1) {
            int mid = lo + (high - lo) / 2;
            if(checkDist(mid, stall)) {
                lo = mid;
            }
            else {
                high = mid;
            }
        }
        cout << lo << '\n';
    }
    return 0;
}
