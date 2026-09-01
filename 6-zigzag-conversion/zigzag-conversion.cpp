#include <string>
#include <vector>
#include <numeric>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        // Base case: no zigzag possible
        if (numRows <= 1 || s.length() <= numRows) {
            return s;
        }

        std::vector<std::string> rows(std::min(numRows, (int)s.length()));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            
            // Reverse direction when reaching top or bottom boundary
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            currentRow += goingDown ? 1 : -1;
        }

        std::string result = "";
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};