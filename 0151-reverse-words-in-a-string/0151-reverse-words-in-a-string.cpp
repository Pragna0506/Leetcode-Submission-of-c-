class Solution {
public:
    string reverseWords(string s) {

        vector<string> words;
        string word = "";

        // Extract words
        for (char ch : s) {
            if (ch != ' ') {
                word += ch;
            } else {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            }
        }

        // Add the last word
        if (!word.empty()) {
            words.push_back(word);
        }

        // Build the answer in reverse order
        string ans = "";

        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];

            if (i != 0)
                ans += " ";
        }

        return ans;
    }
};