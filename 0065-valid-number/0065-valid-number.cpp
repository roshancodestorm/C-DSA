class Solution {
public:
    bool isNumber(string s) {
        bool digit = false, dot = false, exp = false;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                digit = true;
            }
            else if (c == '.') {
                if (dot || exp) return false;
                dot = true;
            }
            else if (c == 'e' || c == 'E') {
                if (exp || !digit) return false;
                exp = true;
                digit = false;
            }
            else if (c == '+' || c == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else {
                return false;
            }
        }

        return digit;
    }
};