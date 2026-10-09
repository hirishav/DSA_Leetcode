#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int sIdx = 0, pIdx = 0;
        int match = 0, starIdx = -1;
        int m = s.length(), n = p.length();

        while (sIdx < m) {
            // Characters match or pattern has '?'
            if (pIdx < n && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            }
            // Pattern has '*', remember positions and try matching 0 characters
            else if (pIdx < n && p[pIdx] == '*') {
                starIdx = pIdx;
                match = sIdx;
                pIdx++;
            }
            // Mismatch: backtrack to the last '*' and let it match one more character
            else if (starIdx != -1) {
                pIdx = starIdx + 1;
                match++;
                sIdx = match;
            }
            // Mismatch and no previous '*' to absorb characters
            else {
                return false;
            }
        }

        // Check if all remaining characters in pattern are '*'
        while (pIdx < n && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == n;
    }
};