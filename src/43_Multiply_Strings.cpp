class Solution {
public:
    string multiply(string num1, string num2) {
        string prod(num1.size()+num2.size(), '0');
        
        for (int i=num1.size()-1; i>=0; i--) {
            int carry = 0;
            for (int j=num2.size()-1; j>=0; j--) {
                int temp = prod[i+j+1] -'0'+ (num1[i]-'0') * (num2[j]-'0') + carry;
                prod[i+j+1] = temp%10 + '0';
                carry = temp/10;
            }
            prod[i] += carry;
        } 
        size_t pos = prod.find_first_not_of("0"); // give the position 
        return pos != string::npos? prod.substr(pos) : "0";  
        //string::npos is the end of string, means no matches in the string 
        //substr(pos) output the string from pos to the end;         
    }
};