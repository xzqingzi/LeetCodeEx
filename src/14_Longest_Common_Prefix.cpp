class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size() || !strs[0].size()) return "";
        int length = strs[0].size(), count;
        for (int i=1; i<strs.size(); i++) {
            count = 0;
            for (int j=0; j<strs[i].size(); j++) {
                if (strs[i][j] != strs[i-1][j]) break;
                count++;
            } 
            length = min(length, count);
        }
        return strs[0].substr(0, length);
    }
};