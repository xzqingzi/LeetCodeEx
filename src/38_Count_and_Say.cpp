class Solution {
public:
    string countAndSay(int n) {
        if (n==0) return "";
        string s = "1";
        string temp;
        int count = 1;
        for (int k=1; k<n; k++) {
            temp = "";
            for (int i=0; i<s.size(); i++) {
                if (s[i]==s[i+1] && i<s.size()-1) {
                    count++;
                }
                else {
                    temp += to_string(count) + s[i]; //General case, convert number to string, but slow here.
                    // convert number to string, can also use:
                    /*   
                    temp += '0'+count; // special case here, may cause problem if number is extremely large 
                    temp += s[i];  // is the same as : temp += char('0'+count) +s[i]
                    */
                    //OR, can also use:
                    /*
                    stringstream ss; // stringstream used for the conversion
                    ss << count << s[i];//add the value of count and s[i] to the characters in the stream
                    temp += ss.str();
                   */
                    count = 1;
                }
            }
            s = temp;
        }
        return s;
    }
};