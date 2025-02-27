#include<iostream>

int main() {
  int n, m;
  std::cin >> n >> m;
  long long cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cnt1 += i * j;
      cnt2 += (i > j) ? j : i;
    }
  }
  std::cout << cnt2 << ' ' << cnt1 - cnt2 << std::endl;
  return 0;
}
