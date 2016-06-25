class Solution {
public:
    int addDigits(int num) {
        //return num- 9*((num-1)/9); // digit root = num- (9*floor[(num-1)/9]);
        //if (num%9 == 0 && num != 0) { return 9;}
        //return num%9;
        int sum = 0;
        while (num >9 ){
            while (num > 0){
                sum += num%10;
                num /= 10;
            }
            num = sum;
            sum = 0;
        }
        return num;
    }
};


// O(1) runtime solution 
class Solution {
public:
    int addDigits(int num) {
        //return num- 9*((num-1)/9); // digit root = num- (9*floor[(num-1)/9]);
        if (num%9 == 0 && num != 0) { return 9;}
        return num%9;
    }
};