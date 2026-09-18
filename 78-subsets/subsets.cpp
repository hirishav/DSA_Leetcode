#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        auto backtrack = [&](auto& self, int start) -> void {
            // Every path down the tree represents a valid subset
            result.push_back(current);

            for (int i = start; i < nums.size(); ++i) {
                current.push_back(nums[i]);
                self(self, i + 1);
                current.pop_back(); // Backtrack
            }
        };

        backtrack(backtrack, 0);
        return result;
    }
};