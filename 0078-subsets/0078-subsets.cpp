class Solution {
public:
    void backtrack(int index, vector<int>& nums,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // Add current subset
        result.push_back(current);

        // Try adding each remaining element
        for (int i = index; i < nums.size(); i++) {

            // Choose
            current.push_back(nums[i]);

            // Explore
            backtrack(i + 1, nums, current, result);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> current;

        backtrack(0, nums, current, result);

        return result;
    }
};