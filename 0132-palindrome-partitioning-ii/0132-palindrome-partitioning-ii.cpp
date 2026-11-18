class Solution {
public:
    int minCut(string s) {
        int n = s.length();

        vector<vector<bool>> pal(n, vector<bool>(n, false));
        vector<int> dp(n, 0);

        // Precompute palindrome substrings
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && 
                    (j - i <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        // Minimum cuts for every prefix
        for (int i = 0; i < n; i++) {
            if (pal[0][i]) {
                dp[i] = 0;
            }
            else {
                dp[i] = i;

                for (int j = 1; j <= i; j++) {
                    if (pal[j][i]) {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};