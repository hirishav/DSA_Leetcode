#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        std::string current = "1";

        for (int i = 2; i <= n; ++i) {
            std::string next_seq = "";
            int len = current.length();

            for (int j = 0; j < len; ) {
                int count = 1;
                while (j + 1 < len && current[j] == current[j + 1]) {
                    count++;
                    j++;
                }

                next_seq += std::to_string(count);
                next_seq += current[j];
                j++;
            }

            current = std::move(next_seq);
        }

        return current;
    }
};