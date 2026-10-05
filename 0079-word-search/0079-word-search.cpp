class Solution {
public:
    int m, n;
    
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int i) {
        if (i == word.size())
            return true;

        if (r < 0 || r >= m || c < 0 || c >= n ||
            board[r][c] != word[i])
            return false;

        char ch = board[r][c];
        board[r][c] = '#'; 
        bool found = dfs(board, word, r + 1, c, i + 1) ||
                     dfs(board, word, r - 1, c, i + 1) ||
                     dfs(board, word, r, c + 1, i + 1) ||
                     dfs(board, word, r, c - 1, i + 1);

        board[r][c] = ch; 

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (dfs(board, word, r, c, 0))
                    return true;
            }
        }

        return false;
    }
};