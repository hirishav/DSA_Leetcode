#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.length();
        int n = t.length();

        if (m < n) return 0;

        // dp[j] represents the number of distinct subsequences of s that equal t[0...j-1]
        // Using unsigned long long to prevent 32-bit overflow during intermediate transitions
        std::vector<unsigned long long> dp(n + 1, 0);

        // An empty target string has exactly 1 subsequence match (the empty string)
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            // Traverse backwards to update in-place without using extra space
            for (int j = n; j >= 1; j--) {
                if (s[i] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return static_cast<int>(dp[n]);
    }
};