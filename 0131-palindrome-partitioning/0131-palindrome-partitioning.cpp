class Solution {
public:
    // Check whether s[left...right] is a palindrome
    bool isPalindrome(string& s, int left, int right) {

        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void backtrack(int start,
                   string& s,
                   vector<string>& current,
                   vector<vector<string>>& result) {

        // We reached the end of the string
        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        // Try every possible substring starting from start
        for (int end = start; end < s.length(); end++) {

            // Only choose a palindrome
            if (!isPalindrome(s, start, end))
                continue;

            // Choose substring
            current.push_back(s.substr(start, end - start + 1));

            // Partition the remaining string
            backtrack(end + 1, s, current, result);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> result;
        vector<string> current;

        backtrack(0, s, current, result);

        return result;
    }
};