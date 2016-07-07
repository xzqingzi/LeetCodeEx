class Solution {
public:
    string convertToTitle(int n) {
        string s;
        int temp = n;
        while (temp) {
            s = char((temp-1)%26 +'A') + s;
            temp = (temp-1)/26;
        }
        return s;
    }
};

//Related to question 171 Excel Sheet Column Number