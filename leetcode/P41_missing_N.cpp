#include<iostream>
#include<vector>

    int firstMissingPositive(std::vector<int>& nums) {
        int rec[100000] = {0};
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 || nums[i] > nums.size()) continue;
            rec[nums[i] - 1] = 1;
        }
        int res = 1;
        for (int i = 0; i <= nums.size(); i++)
            if (rec[i] == 0) {
                res = i + 1;
                break;
            }
        
        return res;
    }

int main (int argc, char *argv[]) {
  std::vector test = {1};
  std::cout << firstMissingPositive(test) << std::endl;
  return 0;
}
