class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> wordset(dictionary.begin(), dictionary.end());

        vector<int> dp(s.length() + 1, 0);

        for (int i = 1; i <= s.length(); i++) {
            dp[i] = dp [i-1] + 1;

            for (int j = 0; j < i; j++) {
                if (wordset.find(s.substr(j, i-j)) != wordset.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        return dp[s.length()];
    }
};
