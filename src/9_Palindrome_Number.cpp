class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){return false;}
        int a=0;  // why not using long, and check overflow, the same as the reverse integer
        int check = x;
        while (x){
            a = a*10+x%10;
            x/=10;
        }
        return a == check;
    }
};

//9-Palindrome Number