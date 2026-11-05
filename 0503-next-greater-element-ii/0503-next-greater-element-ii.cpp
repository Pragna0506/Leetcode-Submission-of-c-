class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        vector<int> answer(n, -1);

        stack<int> st;  // Store indices

        // Traverse the array twice
        for (int i = 0; i < 2 * n; i++) {

            int currentIndex = i % n;

            // Find next greater element
            while (!st.empty() &&
                   nums[currentIndex] > nums[st.top()]) {

                int index = st.top();
                st.pop();

                answer[index] = nums[currentIndex];
            }

            // Only push indices during the first pass
            if (i < n) {
                st.push(currentIndex);
            }
        }

        return answer;
    }
};