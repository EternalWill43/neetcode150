#include <algorithm>
#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum (vector<int> &nums)
    {
        vector<vector<int>> ans;
        int                 n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            int target = nums[i];
            int n_target   = -target;
            int l      = i + 1;
            int r      = n - 1;

            while (l < r)
            {
                int curr_sum = nums[l] + nums[r];
                if (curr_sum == n_target)
                {
                    ans.push_back({ nums[l], nums[r], target });
                    while (l < r && nums[l] == nums[l + 1])
                    {
                        l++;
                    }
                    while (r > l && nums[r] == nums[r - 1])
                    {
                        r--;
                    }
                    r--;
                }
                else if (curr_sum < n_target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
            while (i < n - 1 && target == nums[i + 1])
            {
                i++;
            }
        }
        return ans;
    }
};
