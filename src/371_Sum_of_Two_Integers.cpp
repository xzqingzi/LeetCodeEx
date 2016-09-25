class Solution {
public:
    int getSum(int a, int b) {
        int sum, carry = b;
        while(carry) { // keep calculating until the carry is zero
            sum = carry ^ a; // Calculate the sum without consider the carry
            carry = (carry & a) << 1 ; // Calculate the carry by getting the AND and shifting left
            a = sum;
        }
        return sum;
    }
};