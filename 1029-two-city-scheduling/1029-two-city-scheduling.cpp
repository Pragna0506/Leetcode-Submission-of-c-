class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

        int n = costs.size() / 2;

        // Sort based on how much cheaper A is compared to B
        sort(costs.begin(), costs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return (a[0] - a[1]) < (b[0] - b[1]);
             });

        int totalCost = 0;

        // First n people go to city A
        for (int i = 0; i < n; i++) {
            totalCost += costs[i][0];
        }

        // Remaining n people go to city B
        for (int i = n; i < costs.size(); i++) {
            totalCost += costs[i][1];
        }

        return totalCost;
    }
};