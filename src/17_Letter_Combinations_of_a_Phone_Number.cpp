class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string> {};
        const vector<string> letter = {"", "abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> output;
        output.push_back("");
        
        for(int i=0; i<digits.size(); i++) {
            int num = digits[i]-'1';
            string newLetters = letter[num];
            vector<string> tmp = output;
            output.clear();
            for (int j = 0; j<tmp.size(); j++) {
                for (int k=0; k<newLetters.size(); k++) {
                    output.push_back(tmp[j]+newLetters[k]);
                }
            }
        }
        
        return output;
        
    }
};