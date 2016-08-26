class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> list;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        helper(s, 0, result, list, dp);
        return result;
    }
    
    void helper(string s, int start, vector<vector<string>>& result, vector<string>& list, vector<vector<int>>& dp) {
        if (start == s.size()) {
            result.push_back(list);
            return;
        }
        for (int i=start; i<s.size(); i++) {
            if (isPalindrome(s, start, i, dp)) {
                list.push_back(s.substr(start, i-start+1));
                helper(s, i+1, result, list, dp);
                list.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int i, int j, vector<vector<int>>& dp) { // DONOT forget the & for string s, may cause slower speed
        if (s[i] != s[j]) return 0;
        if (i!=j && i!= j-1 && dp[i+1][j-1] != 1) return 0;
        dp[i][j] = 1;
        return 1;
    }
};


// The other method of isPalindrome, the same runtime, remember to remove dp is func before using it 
    bool isPalindrome(string& s, int i, int j) {
        while (i<=j) {
            if (s[i++] != s[j--]) return 0;
        }
        return 1;
    }