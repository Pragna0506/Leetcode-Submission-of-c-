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

        // Try each candidate
        for (int i = start; i < candidates.size(); i++) {

            // Candidate is too large
            if (candidates[i] > target)
                continue;

            // Choose
            current.push_back(candidates[i]);

            // Reuse the same candidate
            backtrack(i, candidates, target - candidates[i],
                      current, result);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                        int target) {

        vector<vector<int>> result;
        vector<int> current;

        // Sorting helps us stop early
        sort(candidates.begin(), candidates.end());

        backtrack(0, candidates, target, current, result);

        return result;
    }
};