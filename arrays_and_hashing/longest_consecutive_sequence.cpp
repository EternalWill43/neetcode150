#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
   public:
    int longestConsecutive(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        if (nums.size() == 0) return {};
        auto last = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), last));
        int ans = 1;
        int r = 1, n = nums.size();
        int count = 1;
        while (r < n)
        {
            if (nums[r] - nums[r - 1] == 1)
            {
                ++count;
                if (count > ans) ans = count;
                ++r;
            }
            else
            {
                count = 1;
                ++r;
            }
        }
        return ans;
    }
};