

//brute force, Vey Slow solution
class Solution { //One unique longest palindromic substring
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int sum1, sum2, left, right,sum=0, outleft;
        
        for (int i=0; i<s.size()-sum/2; i++) {
            if (s[i] == s[i+1]) {
                cout<<"k1"<<endl;
                left = i;
                right = i+1;
                sum1 = 0;
                while(s[left] == s[right] && left>=0 && right<s.size()) {
                    sum1 +=2;
                    left--;
                    right++;
                }
                if (sum1>sum) {
                    sum = sum1;
                    cout<<sum<<endl;
                    outleft = left;
                }
            }
            if (s[i] == s[i+2]) {
                cout<<"k2"<<endl;
                left = i;
                right = i+2;
                sum2 = 1;
                while(s[left] == s[right] && left>=0 && right<s.size()) {
                    sum2 +=2;
                    left--;
                    right++;
                }
                if (sum2>sum) {
                    sum = sum2;
                    cout<<sum<<endl;
                    outleft = left;
                }
            }
        }
        return s.substr(outleft+1, sum);
        
    }
};