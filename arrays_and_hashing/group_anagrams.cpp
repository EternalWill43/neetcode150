#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
   public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (auto str : strs)
        {
            string s = str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto &k : mp)
        {
            ans.push_back(k.second);
        }
        return ans;
    }
};
