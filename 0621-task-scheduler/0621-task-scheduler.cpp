class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        // Count frequency of each task
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Find the maximum frequency
        int maxFreq = 0;

        for (int count : freq) {
            maxFreq = max(maxFreq, count);
        }

        // Count how many tasks have the maximum frequency
        int maxCount = 0;

        for (int count : freq) {
            if (count == maxFreq) {
                maxCount++;
            }
        }

        // Calculate the minimum intervals
        int intervals = (maxFreq - 1) * (n + 1) + maxCount;

        return max((int)tasks.size(), intervals);
    }
};
