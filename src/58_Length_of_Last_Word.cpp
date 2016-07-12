class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int n = s.find_last_not_of(' ');  
        for (int i=n; i>=0; i--) {
            if (s[i] == ' ') { return count;}
            count++;
        }
        return count;
    }
};


// Other build in func solution 
class Solution {
public:
    int lengthOfLastWord(string s) {
        while(s.back()==' ') s.erase(s.length()-1); //while last pos are ' ', remove them , until the last pos is digit
        return s.length()-s.rfind(' ')-1; // rfind() gives the last pos of ' '
    }
};


//Others solution

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int pos;
        
        while (s.length()!=0){
            pos = s.find(" ");
            if (pos==string::npos)  // Used in string, means "until the end of the string".
                return s.length();
            else{
                if (pos!=0)
                    len = pos;
                s.erase(0,pos+1);
            }
        }
        return len;
    }
};