#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isAnagram (string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        vector<int> word1(26);
        vector<int> word2(26);
        for (char &c : s)
        {
            ++word1[(int)c - 'a'];
        }
        for (char &c : t)
        {
            ++word2[(int)c - 'a'];
        }
        for (int i = 0; i < 26; i++)
        {
            if (word1[i] != word2[i])
            {
                return false;
            }
        }
        return true;
    }
};
