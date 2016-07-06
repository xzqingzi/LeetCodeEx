class Solution {
public:
    int titleToNumber(string s) {
        int temp=0;
        for (int i=0; i<s.size(); i++) {
            temp *=26;
            temp += (s[i]-'A'+1);
            //temp += (s[i]-'A'+1)*pow(26,(s.size()-i-1)); // pow is a little bit slower
        }
        return temp;
    }
};


//Related to question 168. Excel Sheet Column title