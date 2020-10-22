/*
contest link : https://www.codechef.com/OCT20B
question link : https://www.codechef.com/OCT20B/problems/REPLESX
*/

#include<iostream>
#include<algorithm>
using namespace std;
int finInd(int a[], int n, int x, int p) {
    int min = 100000000, minp=-1;
    for(int i=0;i<n;i++){
        if(a[i] == x) {
            if(abs(p-i) < min) {
                min = abs(p-i);
                minp = i;
            }
        }
    }
    return minp;
}
void solve() {
    int N, X, p, k;
    cin >> N >> X >> p >> k;
    int a[N];
    for(int i=0;i<N;i++)
    cin >> a[i];
    sort(a, a+N);
    int index = finInd(a, N, X, p);
    int count = 0;
    if(a[index] != X) {
        a[k-1] = X;
        sort(a, a+N);
        count++;
    }
    if(a[p-1] == X) {
        cout << 0+count;
        return;
    }
    if(p < k && a[p-1] < X) {
        cout << -1;
        return;
    }
    if(p > k && a[p-1] > X) {
        cout << -1;
        return;
    }
    index = finInd(a, N, X, p)+1;
    cout << abs(p-index)+count;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
return 0;
}
