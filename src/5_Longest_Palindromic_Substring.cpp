

//brute force, Vey Slow solution
class Solution { //One unique longest palindromic substring
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int sum1, sum2, left, right,sum=0, outleft;
        
        for (int i=0; i<s.size()-sum/2; i++) {
            if (s[i] == s[i+1]) {
                left = i;
                right = i+1;
                sum1 = 0;
                while(s[left] == s[right] && left>=0 && right<s.size()) {
                    sum1 +=2;
                    left--;
                    right++;
                }
                if (sum1>sum) {
                    sum = sum1;
                
                    outleft = left;
                }
            }
            if (s[i] == s[i+2]) {
                left = i;
                right = i+2;
                sum2 = 1;
                while(s[left] == s[right] && left>=0 && right<s.size()) {
                    sum2 +=2;
                    left--;
                    right++;
                }
                if (sum2>sum) {
                    sum = sum2;
                    outleft = left;
                }
            }
        }
        return s.substr(outleft+1, sum);
        
    }
};



// DP draft
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> result(s.size(), vector<bool> (s.size(), 0));
        DPcheck(result, s, 0, s.size()-1);
        
        
    }
    
    void DPcheck(vector<vector<bool>>& result, string& s, int i, int j) {
        if ( i == j ) result[i][j] = 1; return;
        if (i+1 == j && s[i]==s[j]) result[i][j] = 1; return;        
        DPcheck(result, s, i+1, j-1);        
        if ( s[i] == s[j] && result[i+1][j-1] ) result[i][j] = 1;
        return; 
    }
};