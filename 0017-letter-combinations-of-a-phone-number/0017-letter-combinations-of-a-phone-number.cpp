class Solution {
public:
void backtrack(int index,
                   string& digits,
                   string& current,
                   vector<string>& result,
                   vector<string>& letters) {

        // We have selected one letter for every digit
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        // Get letters for the current digit
        string possibleLetters = letters[digits[index] - '0'];

        // Try every possible letter
        for (char letter : possibleLetters) {

            // Choose
            current.push_back(letter);

            // Move to the next digit
            backtrack(index + 1,
                      digits,
                      current,
                      result,
                      letters);

            // Undo choice
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> result;

        if (digits.empty())
            return result;

        vector<string> letters = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        string current;

        backtrack(0, digits, current, result, letters);

        return result;
    }
}; 