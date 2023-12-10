#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> m;
    m[nums[0]] = 0;
    for (int i = 1; i < nums.size(); i++) {
      int looking_for = target - nums[i];
      if (m.find(looking_for) != m.end()) {
        return {m[looking_for], i};
      } else {
        m[nums[i]] = i;
      }
    }
    return {-1, -1};
  }
};
