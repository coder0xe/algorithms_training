#include <stdio.h>
#include <stdlib.h>

int *findDuplicates(int *nums, int numsSize, int *returnSize) {
  int i = 0, pos = 0;
  int *res = (int *)malloc(sizeof(int) * numsSize / 2);
  for (; i < numsSize; i++) {
    int x = abs(nums[i]);
    if (nums[x - 1] > 0)
      nums[x - 1] *= -1;
    else
      res[pos++] = x;
  }
  *returnSize = pos;
  return res;
}

int main() {
  int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
  int returnSize = 0;
  int *res = findDuplicates(nums, 8, &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("%d ", res[i]);
  }
  return 0;
}