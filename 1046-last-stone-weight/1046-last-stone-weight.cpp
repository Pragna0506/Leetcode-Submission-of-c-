class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> maxHeap;

        // Put all stones into max heap
        for (int stone : stones) {
            maxHeap.push(stone);
        }

        // Smash the two heaviest stones
        while (maxHeap.size() > 1) {

            int y = maxHeap.top();
            maxHeap.pop();

            int x = maxHeap.top();
            maxHeap.pop();

            // If they are different, put the difference back
            if (x != y) {
                maxHeap.push(y - x);
            }
        }

        // One stone remaining
        if (!maxHeap.empty()) {
            return maxHeap.top();
        }

        return 0;
    }
};