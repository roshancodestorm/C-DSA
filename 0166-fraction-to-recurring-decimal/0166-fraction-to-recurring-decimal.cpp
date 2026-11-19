
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        if (numerator == 0) return "0";

        string ans;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) {
            ans += "-";
        }

        // Convert to long long to avoid overflow
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);

        // Integer part
        ans += to_string(n / d);

        long long rem = n % d;

        if (rem == 0) return ans;

        ans += ".";

        unordered_map<long long, int> mp;

        while (rem != 0) {

            // Repeating remainder found
            if (mp.count(rem)) {
                ans.insert(mp[rem], "(");
                ans += ")";
                break;
            }

            mp[rem] = ans.size();

            rem *= 10;

            ans += to_string(rem / d);

            rem %= d;
        }

        return ans;
    }
};
