class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> list;
        if (n==0) return list;
        generate(list, "", n, 0);
        return list;
    }
    
    void generate(vector<string>& list, string s, int open, int close) {
        if (open == 0 && close == 0) {
            list.push_back(s);
            return;
        }
        if (open>0) generate(list, s+"(", open-1, close+1);
        if (close>0) generate(list, s+")", open, close-1);
    }
};