class Solution {
public:
    void backtrack(int start, int n, int k,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // Combination has exactly k numbers
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Try every possible next number
        for (int i = start; i <= n; i++) {

            // Choose
            current.push_back(i);

            // Explore
            backtrack(i + 1, n, k, current, result);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> result;
        vector<int> current;

        backtrack(1, n, k, current, result);

        return result;
    }
};