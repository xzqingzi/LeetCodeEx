class Solution { //In logarithmic time complexity.
public:
    int trailingZeroes(int n) {
        int sum = 0,temp = n;
        while (temp>=5) {
            temp /= 5;
            sum += temp;
        }
    return sum;
    }
};