#include <iostream>

int main() {
  int a[10] = {1, 2, 3, 5, 6, 7, 8, 9};
  int key = 4;
  int low = 0, high = 7;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] == key) {
      std::cout << "Element found at index " << mid << std::endl;
      return 0;
    } else if (a[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  std::cout << "Element not found and now low is " << low << ", high is "
            << high << std::endl;
  return 0;
}