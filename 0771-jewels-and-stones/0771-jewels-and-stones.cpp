class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        unordered_set<char> jewelSet;
        
        // Store all jewels
        for (char ch : jewels) {
            jewelSet.insert(ch);
        }
        
        int count = 0;
        
        // Check each stone
        for (char ch : stones) {
            if (jewelSet.count(ch)) {
                count++;
            }
        }
        
        return count;
    }
};