class Solution {
public:
    void backtrack(int start,
                   vector<int>& candidates,
                   int target,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // Target reached
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate choices at the same level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no later number will work
            if (candidates[i] > target)
                break;

            // Choose
            current.push_back(candidates[i]);

            // Move to next index because each number
            // can be used only once
            backtrack(i + 1,
                      candidates,
                      target - candidates[i],
                      current,
                      result);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        vector<vector<int>> result;
        vector<int> current;

        // Sort so duplicates are together
        sort(candidates.begin(), candidates.end());

        backtrack(0, candidates, target, current, result);

        return result;
    }
};