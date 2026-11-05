class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequency
        unordered_map<int, int> frequency;

        for (int num : nums) {
            frequency[num]++;
        }

        // Step 2: Create buckets
        // bucket[i] contains numbers that appear i times
        vector<vector<int>> buckets(nums.size() + 1);

        for (auto& pair : frequency) {
            int num = pair.first;
            int count = pair.second;

            buckets[count].push_back(num);
        }

        // Step 3: Take elements from highest frequency
        vector<int> result;

        for (int freq = nums.size(); freq >= 1; freq--) {

            for (int num : buckets[freq]) {
                result.push_back(num);

                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};