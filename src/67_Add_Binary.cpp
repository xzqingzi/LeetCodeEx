class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        int i = a.size()-1, j = b.size()-1, carry = 0,temp;
        while (i>=0 && j>=0) {
            temp = a[i] +b[j] -'0'-'0'+carry;
            carry = temp/2;
            c = char(temp%2+'0') + c;   // is the same as : tt = temp%2+'0'; c = tt + c; 
            i--;
            j--;
        }
        while (i>=0) {
            temp = a[i]-'0' +carry; 
            carry = temp/2;
            c = char(temp%2 + '0') + c; 
            i--;
        }
        while (j>=0) {
            temp = b[j] -'0' +carry; 
            carry = temp/2;
            c = char(temp%2 +'0') + c;
            j--;
        }
        if (carry != 0) {
            c = char(carry +'0') + c;
        }
        return c;
    }
};