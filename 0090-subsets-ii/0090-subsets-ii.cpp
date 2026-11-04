class Solution {
public:
    void backtrack(int start,
                   vector<int>& nums,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // Add the current subset
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > start && nums[i] == nums[i - 1])
                continue;

            // Choose
            current.push_back(nums[i]);

            // Explore
            backtrack(i + 1, nums, current, result);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // Put duplicates next to each other
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, nums, current, result);

        return result;
    }
};
