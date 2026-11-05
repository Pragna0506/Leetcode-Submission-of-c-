class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            bool valid = true;
            int previousMax = -1;

            for (int start = 0; start < n && valid; start += k) {
                int mn = INT_MAX;
                int mx = INT_MIN;
                int descents = 0;

                for (int j = 0; j < k; j++) {
                    int current = nums[start + j];
                    int next = nums[start + (j + 1) % k];

                    if (current > next) {
                        descents++;
                    }

                    mn = min(mn, current);
                    mx = max(mx, current);
                }

                if (descents > 1 ||
                    (start > 0 && previousMax > mn)) {
                    valid = false;
                }

                previousMax = mx;
            }

            if (valid) {
                answer += k;
            }
        }

        return answer;
    }
};