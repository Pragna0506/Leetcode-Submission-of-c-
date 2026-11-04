class Solution {
public:
    void backtrack(vector<int>& nums,
                   vector<bool>& used,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // We have formed one complete permutation
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        // Try every number
        for (int i = 0; i < nums.size(); i++) {

            // Skip if this number is already used
            if (used[i])
                continue;

            // Choose
            used[i] = true;
            current.push_back(nums[i]);

            // Explore
            backtrack(nums, used, current, result);

            // Undo choice
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, used, current, result);

        return result;
    }
};