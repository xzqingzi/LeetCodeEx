class Solution {
public:
    int numDecodings(string s) {
        if (!s.size()||s[0] == '0') return 0;
        if (s.size() == 1) return 1;
        int a=1, b=1;
        int prev, curr, temp;
        prev = s[0]-'0';
        for (int i=1; i<s.size(); i++) {
            curr = s[i]-'0';
            temp = prev*10+curr;
            if (curr == 0) {
                if (prev == 0 || prev>= 3) return 0;
                else {
                    prev = curr; 
                    continue;
                }
            }  
            else if (10 <=temp && temp < 27) {
                if (i%2) b = a+b;
                else a = a+b;
            }
            else {
                if (i%2) b = a;
                else a = b;
            }
            prev = curr;
        }
        return (s.size()%2)? a:b;
    }
};