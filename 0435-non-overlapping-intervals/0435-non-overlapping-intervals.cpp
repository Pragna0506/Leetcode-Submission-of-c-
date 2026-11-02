class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        // Sort by ending time
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        int removed = 0;

        // End of the last interval we kept
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            // Overlap
            if (intervals[i][0] < end) {
                removed++;
            }
            else {
                // No overlap, keep this interval
                end = intervals[i][1];
            }
        }

        return removed;
    }
};