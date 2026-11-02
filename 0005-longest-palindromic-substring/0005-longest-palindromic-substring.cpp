
class Solution {
public:
    int start = 0;
    int maxLength = 0;

    void expandAroundCenter(string& s, int left, int right) {
        while (left >= 0 &&
               right < s.length() &&
               s[left] == s[right]) {
            left--;
            right++;
        }

        // The pointers moved one step beyond the palindrome
        int length = right - left - 1;

        if (length > maxLength) {
            maxLength = length;
            start = left + 1;
        }
    }

    string longestPalindrome(string s) {
        for (int i = 0; i < s.length(); i++) {
            // Odd-length palindrome
            expandAroundCenter(s, i, i);

            // Even-length palindrome
            expandAroundCenter(s, i, i + 1);
        }

        return s.substr(start, maxLength);
    }
};
