class Solution {
public:
    int count = 0;
    vector<bool> col, diag1, diag2;

    void solve(int row, int n) {
        if(row == n) {
            count++;
            return;
        }

        for(int j = 0; j < n; j++) {
            if(col[j] || diag1[row - j + n - 1] || diag2[row + j])
                continue;

            col[j] = diag1[row - j + n - 1] = diag2[row + j] = true;

            solve(row + 1, n);

            col[j] = diag1[row - j + n - 1] = diag2[row + j] = false;
        }
    }

    int totalNQueens(int n) {
        col.resize(n, false);
        diag1.resize(2 * n - 1, false);
        diag2.resize(2 * n - 1, false);

        solve(0, n);
        return count;
    }
};