#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum (vector<int> &numbers, int target)
    {
        vector<int> ans;
        int         l = 0;
        int         r = numbers.size() - 1;
        while (l < r && l < numbers.size() && r > 0)
        {
            int sum = numbers[l] + numbers[r];
            if (sum == target)
            {
                return { l + 1, r + 1 };
            }
            if (sum < target)
            {
                ++l;
                continue;
            }
            if (sum > target)
            {
                ++r;
                continue;
            }
        }
        return ans;
    }
};
