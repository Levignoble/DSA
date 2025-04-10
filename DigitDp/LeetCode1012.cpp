class Solution {
public:
    unordered_map<string, int> dp;

    int solve(string &s, int i, int mask, bool tight, bool repeat) {
        if (i == s.size()) return repeat;

        string key = to_string(i) + "|" + to_string(mask) + "|" + to_string(tight) + "|" + to_string(repeat);
        if (dp.count(key)) return dp[key];

        int limit = tight ? s[i] - '0' : 9;
        int ans = 0;

        for (int d = 0; d <= limit; d++) {
            // skip leading zeros unless it's not the first digit
            if (mask == 0 && d == 0) {
                ans += solve(s, i + 1, mask, tight && (d == limit), repeat);
                continue;
            }

            bool is_repeat = (mask & (1 << d)) != 0;
            int new_mask = mask | (1 << d);

            ans += solve(s, i + 1, new_mask, tight && (d == limit), repeat || is_repeat);
        }

        return dp[key] = ans;
    }

    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        return solve(s, 0, 0, true, false);
    }
};
