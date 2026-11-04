 class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Sort intervals by starting point
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        // Add the first interval
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {

            // Current interval overlaps with last interval
            if (intervals[i][0] <= result.back()[1]) {

                result.back()[1] =
                    max(result.back()[1], intervals[i][1]);
            }
            else {
                // No overlap
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};