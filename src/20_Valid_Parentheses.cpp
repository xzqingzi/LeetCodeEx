class Solution {
public:
    bool isValid(string s) {
        vector<char> list;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(' ||s[i] == '{' || s[i] == '[') {
               list.push_back(s[i]); 
            }
            else if (s[i] == ')') {
                if (list.size()==0 || list.back() != '(') return false;
                list.pop_back();
            }
            else if (s[i] == ']') {
                if (list.size()==0 || list.back() != '[') return false;
                list.pop_back();
            }
            else if (s[i] == '}') {
                if (list.size()==0 || list.back() != '{') return false;
                list.pop_back();
            }
        }
        if(list.size() !=0) return false;
        return true;
    }
};