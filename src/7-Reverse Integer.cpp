class Solution {
public:
    int reverse(int x) {
        long out = 0; // int has maximum
        while(x){
            int a = x%10; 
            x/=10;
            out = out*10+a;
        }
        //return out;
        if (out>0){return out > INT_MAX ? 0 : out;}  
        else {return out < INT_MIN ? 0 : out;}
        // condition ? result1 : result2 , if ture, result1; o.w., result2
        //INT_MAX & INT_MIN are the maximum and minimum values that int can hold.
    }
    
};