class Solution {
public:
    bool isHappy(int n) {
        while (n>9) {
            n = GetSum(n);
        }
        if (n == 1 || n==7) return 1;
        return 0;
    }
    
    int GetSum(int num) {
        int temp = num, sum=0, remain;
        while (temp>0) {
            remain = temp%10;
            temp /= 10;
            sum += remain*remain;
        }
        return sum;
    }
};