class Solution {
public:
    void backtrack(vector<int>& nums,
                   vector<bool>& used,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // Complete permutation
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // Already used
            if (used[i])
                continue;

            // Skip duplicate choices at the same level
            if (i > 0 &&
                nums[i] == nums[i - 1] &&
                !used[i - 1]) {
                continue;
            }

            // Choose
            used[i] = true;
            current.push_back(nums[i]);

            // Explore
            backtrack(nums, used, current, result);

            // Undo
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> current;

        // Put duplicates together
        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);

        backtrack(nums, used, current, result);

        return result;
    }
};