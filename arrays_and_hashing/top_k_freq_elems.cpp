#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

/* If we were working with actual data streaming in,
 * we would probably just use a priority queue instead of a vector
 * but the pq would be log(n) on every insert, we can just insert into
 * the back of the vector at (usually) O(1) and then just do the single nlogn
 * sort at the end, but realistically this is a good example of where to use a
 * pq */
// TL;DR vector instead of PQ because for leetcode prework ends up with faster
// runtime

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    if (k == nums.size())
      return nums;

    unordered_map<int, int> m;
    for (int i : nums) {
      m[i]++;
    }

    auto comp = [](const pair<int, int> &a, const pair<int, int> &b) {
      return a.second > b.second || (a.second == b.second && a.first > b.first);
    };
    vector<pair<int, int>> vec;

    for (const auto &[key, value] : m) {
      vec.push_back({key, value});
    }
    sort(vec.begin(), vec.end(), comp);

    vector<int> ans;
    while (k-- > 0) {
      ans.push_back(vec.back().second);
      vec.pop_back();
    }
    return ans;
  }
};
