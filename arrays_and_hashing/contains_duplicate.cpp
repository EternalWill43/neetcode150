#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> m;
    for (int i : nums) {
      if (m[i])
        return true;
      else
        m[i]++;
    }
    return false;
  }
};
