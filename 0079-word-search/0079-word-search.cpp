class Solution {
public:
    bool backtrack(vector<vector<char>>& board,
                   string& word,
                   int row,
                   int col,
                   int index) {

        // We found the complete word
        if (index == word.length())
            return true;

        // Check boundaries
        if (row < 0 || row >= board.size() ||
            col < 0 || col >= board[0].size()) {
            return false;
        }

        // Current cell doesn't match
        if (board[row][col] != word[index])
            return false;

        // Mark cell as visited
        char original = board[row][col];
        board[row][col] = '#';

        // Explore 4 directions
        bool found =
            backtrack(board, word, row + 1, col, index + 1) ||
            backtrack(board, word, row - 1, col, index + 1) ||
            backtrack(board, word, row, col + 1, index + 1) ||
            backtrack(board, word, row, col - 1, index + 1);

        // Undo the visited mark
        board[row][col] = original;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        // Try every cell as a starting point
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (board[row][col] == word[0]) {

                    if (backtrack(board, word,
                                  row, col, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};