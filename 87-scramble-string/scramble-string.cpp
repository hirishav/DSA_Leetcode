#include <string>
#include <unordered_map>
#include <vector>

class Solution {
private:
    std::unordered_map<std::string, bool> memo;

public:
    bool isScramble(std::string s1, std::string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;

        std::string key = s1 + "#" + s2;
        if (memo.count(key)) {
            return memo[key];
        }

        int n = s1.length();

        // Pruning: check if both strings are anagrams
        std::vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int c : count) {
            if (c != 0) {
                return memo[key] = false;
            }
        }

        // Try splitting at every possible point
        for (int i = 1; i < n; i++) {
            // Case 1: Substrings are NOT swapped
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // Case 2: Substrings ARE swapped
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }
};