/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (30.33%)
 * Total Accepted:    252.8K
 * Total Submissions: 831.6K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        return existDFS(board, word);
    }
    // T: O(m*n*k) S: O(k)
    // m=len(rows) n=len(cols) k=len(word)
    bool existDFS(vector<vector<char>>& board, const string& word) {
        if (board.empty()) return false;
        if (board[0].empty()) return false;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (existDFSHelper(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool existDFSHelper(vector<vector<char>>& board, const string& word, int word_index, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
            return false;
        }
        if (board[x][y] != word[word_index]) {
            return false;
        }
        if (word_index == word.size() - 1) {
            return true;
        }
        
        board[x][y] = '\0';
        static int directions[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto dir : directions) {
            if (existDFSHelper(board, word, word_index + 1, x + dir[0], y + dir[1])) {
                return true;
            }
        }
        board[x][y] = word[word_index];

        return false;
    }
};

