#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            unordered_set<char> window;

            int left = 0;
            int maxLength = 0;

            for(int right = 0; right < s.length(); right++)
            {
                // if duplicate found -> shrink window
                while (window.count(s[right]))
                {
                    window.erase(s[left]);
                    left++;
                }

                // add current char
                window.insert(s[right]);

                // update max length
                maxLength = max(maxLength, right - left + 1);
            }
            return maxLength;
        }
};

int main()
{
    Solution sol;
    string s = "abcabcdcbb";

    cout << "Longest length: " << sol.lengthOfLongestSubstring(s);

    return 0;
}
