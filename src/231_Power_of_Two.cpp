class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n & (n-1)); // & means "AND" 
    }
};
// number saved are all binary ?