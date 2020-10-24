#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] * (n - i) > ans) {
      ans = a[i] * (n - i);
    }
  }
  cout << ans << endl;
}
