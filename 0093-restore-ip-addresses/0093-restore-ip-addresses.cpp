class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n = s.size();

        for (int i = 1; i <= 3 && i < n; i++) {
            for (int j = i + 1; j <= i + 3 && j < n; j++) {
                for (int k = j + 1; k <= j + 3 && k < n; k++) {
                    string a = s.substr(0, i);
                    string b = s.substr(i, j - i);
                    string c = s.substr(j, k - j);
                    string d = s.substr(k);

                    if (d.size() > 3) continue;

                    if (valid(a) && valid(b) &&
                        valid(c) && valid(d)) {
                        ans.push_back(a + "." + b + "." +
                                      c + "." + d);
                    }
                }
            }
        }

        return ans;
    }

    bool valid(string s) {
        if (s.empty() || s.size() > 3) return false;
        if (s.size() > 1 && s[0] == '0') return false;
        return stoi(s) <= 255;
    }
};