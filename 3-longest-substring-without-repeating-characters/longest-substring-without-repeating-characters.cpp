#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Vector storing the last seen index + 1 for each ASCII character (initialized to 0)
        std::vector<int> last_pos(128, 0);
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            unsigned char c = s[right];
            
            // If character was seen inside the current window, shrink the window from left
            left = std::max(left, last_pos[c]);
            
            // Update max window length
            max_len = std::max(max_len, right - left + 1);
            
            // Store next possible valid left position
            last_pos[c] = right + 1;
        }

        return max_len;
    }
};