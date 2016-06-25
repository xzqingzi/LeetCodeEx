class Solution { // What is the most significant digit
public:
    vector<int> plusOne(vector<int>& digits) {
        int temp = 1;
        for (int i = digits.size()-1; i >= 0; --i){
            int num = digits[i] + temp;
            digits[i] = num%10;
            temp = num/10;
            if (!temp) {break;}  //!temp means temp == 0
        } 
        if (temp) {digits.insert(digits.begin(), temp);} // When the first digit is 9 
        return digits;
    }
};

// how to use digits.begin() and .end() for index ?