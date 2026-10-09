#include <string>
#include <vector>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::vector<int> numbers;
        int fact = 1;

        // Populate available numbers and compute (n - 1)!
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        // Convert k to 0-indexed
        k--;

        std::string result = "";
        for (int i = n; i >= 1; i--) {
            int index = k / fact;
            result += std::to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);

            if (i > 1) {
                k %= fact;
                fact /= (i - 1);
            }
        }

        return result;
    }
};