class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int n = s.find_last_not_of(' ');  
        for (int i=n; i>=0; i--) {
            if (s[i] == ' ') { return count;}
            count++;
        }
        return count;
    }
};