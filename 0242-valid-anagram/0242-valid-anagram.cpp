class Solution {
public:
    bool isAnagram(string s, string t) {

        // Anagrams must have the same length
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> freq(26, 0);

        // Count characters in s
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Remove characters using t
        for (char ch : t) {
            freq[ch - 'a']--;

            // More occurrences in t than s
            if (freq[ch - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};