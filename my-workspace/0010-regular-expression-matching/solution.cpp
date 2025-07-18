class Solution {
public:
    /**
     * @brief Checks if the input string s matches the given pattern p.
     * * This function uses a top-down dynamic programming approach with memoization
     * to solve the regular expression matching problem.
     * * @param s The input string (contains only lowercase English letters).
     * @param p The pattern (contains lowercase English letters, '.', and '*').
     * @return true if the entire string s matches the pattern p, false otherwise.
     */
    bool isMatch(string s, string p) {
        // The memoization table. `memo[i][j]` will store the result of isMatch(s[i:], p[j:]).
        // We initialize it with -1 to indicate that the state has not been computed yet.
        // 0 will represent false, and 1 will represent true.
        // The dimensions are s.length() + 1 and p.length() + 1 to handle the empty string/pattern cases.
        vector<vector<int>> memo(s.length() + 1, vector<int>(p.length() + 1, -1));
        return solve(0, 0, s, p, memo);
    }

private:
    /**
     * @brief The recursive helper function that performs the matching.
     * * @param i The current index in the string s.
     * @param j The current index in the pattern p.
     * @param s The input string.
     * @param p The pattern.
     * @param memo The memoization table to store results of subproblems.
     * @return true if s from index i matches p from index j.
     */
    bool solve(int i, int j, const string& s, const string& p, vector<vector<int>>& memo) {
        // If the result for this state (i, j) is already computed, return it from the cache.
        if (memo[i][j] != -1) {
            return memo[i][j] == 1;
        }

        bool ans;

        // Base Case: If we've reached the end of the pattern...
        if (j == p.length()) {
            // ...the match is successful only if we've also reached the end of the string.
            ans = (i == s.length());
        } else {
            // Check if the first character of the current substring and pattern match.
            // A match occurs if the characters are the same or if the pattern has a '.'
            bool first_match = (i < s.length()) && (p[j] == s[i] || p[j] == '.');

            // Check if the next character in the pattern is a '*'
            if (j + 1 < p.length() && p[j + 1] == '*') {
                // If we have a '*' two cases are possible:
                // 1. The '*' matches zero instances of the preceding element.
                //    In this case, we can just skip over the `p[j]*` part of the pattern.
                //    This is represented by `solve(i, j + 2, ...)`.
                // 2. The '*' matches one or more instances of the preceding element.
                //    This is only possible if the first characters matched (`first_match`).
                //    If they did, we advance the string pointer `i` but keep the pattern
                //    pointer `j` the same, as `*` can match multiple characters.
                //    This is represented by `first_match && solve(i + 1, j, ...)`.
                ans = solve(i, j + 2, s, p, memo) || (first_match && solve(i + 1, j, s, p, memo));
            } else {
                // Standard match: No '*' is involved.
                // The match is successful only if the first characters match AND the rest of the strings match.
                ans = first_match && solve(i + 1, j + 1, s, p, memo);
            }
        }

        // Cache the result before returning.
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
};
