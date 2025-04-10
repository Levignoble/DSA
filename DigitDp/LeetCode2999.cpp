class Solution {
public:
    long long numberOfPowerfulInt(long long start,
                                  long long finish,
                                  int limit,
                                  string s) {
        return countWithSuffix(finish, limit, s)
             - countWithSuffix(start - 1, limit, s);
    }

private:
    // Count how many numbers in [0 .. val] have 's' as their decimal suffix
    // and all other digits ≤ limit.
    long long countWithSuffix(long long val,
                              int limit,
                              const string& suffix) {
        string str = to_string(val);
        int n = str.size();
        int m = suffix.size();

        // If val has fewer digits than suffix, there are none.
        if (n < m) return 0;

        int prefixLen = n - m;
        // dp[i][tight]:
        //  - i = position in the prefix (0 .. prefixLen)
        //  - tight = 1 if we've matched all previous prefix digits exactly to str,
        //            0 if we've already gone strictly below
        vector<array<long long,2>> dp(prefixLen + 1);
        
        // Base case at the boundary between prefix and suffix:
        //  - dp[prefixLen][0] = 1 : once prefix is free, there's exactly 1 way
        //                         to choose the suffix (we'll check it below)
        //  - dp[prefixLen][1] = (str_suffix >= suffix ? 1 : 0)
        //     i.e. if the suffix of str is at least the target suffix,
        //     we can stay tight and still pick exactly that suffix.
        dp[prefixLen][0] = 1;
        dp[prefixLen][1] = (str.substr(prefixLen) >= suffix ? 1LL : 0LL);

        // Fill DP backwards through the prefix
        for (int i = prefixLen - 1; i >= 0; --i) {
            int digit = str[i] - '0';

            // If we're already free (tight=0), we can put any of [0..limit] here
            // and remain free for the next position:
            //   (limit+1) choices × dp[i+1][0]
            dp[i][0] = (limit + 1) * dp[i+1][0];

            // If we're tight (tight=1), we can only place 0..digit here,
            // but capped by limit. Two cases:
            //  1) digit <= limit:
            //       we can place [0..digit-1] → that moves to free: digit * dp[i+1][0]
            //       we can place exactly digit   → remains tight: dp[i+1][1]
            //  2) digit > limit:
            //       we can place [0..limit] only → moves to free: (limit+1)*dp[i+1][0]
            if (digit <= limit) {
                dp[i][1] = (long long)digit * dp[i+1][0]
                         + dp[i+1][1];
            } else {
                dp[i][1] = (long long)(limit + 1) * dp[i+1][0];
            }
        }
        // The answer is “number of ways to fill the prefix exactly (=tight=1)”
        // which then forces the suffix to be checked by our base case.
        return dp[0][1];
    }
};
