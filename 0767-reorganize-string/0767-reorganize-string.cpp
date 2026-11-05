class Solution {
public:
    string reorganizeString(string s) {

        // Count frequency of each character
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Max heap: {frequency, character}
        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], 'a' + i});
            }
        }

        string result = "";

        // Previous character and its remaining frequency
        pair<int, char> previous = {0, '#'};

        while (!pq.empty()) {

            // Take character with highest frequency
            auto current = pq.top();
            pq.pop();

            result += current.second;

            // Previous character can now be used again
            if (previous.first > 0) {
                pq.push(previous);
            }

            // Decrease current character's frequency
            current.first--;

            // Store current as previous
            previous = current;
        }

        // Check if all characters were successfully placed
        if (result.length() != s.length()) {
            return "";
        }

        return result;
    }
};