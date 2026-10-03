class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();

        for (int i = 0; i < n;) {
            int j = i;
            int len = 0;

            while (j < n && len + words[j].size() + (j - i) <= maxWidth) {
                len += words[j].size();
                j++;
            }

            int spaces = maxWidth - len;
            int gaps = j - i - 1;

            string line;
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    if (k > i) line += " ";
                    line += words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int each = spaces / gaps;
                int extra = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        line += string(each + (k - i < extra ? 1 : 0), ' ');
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};