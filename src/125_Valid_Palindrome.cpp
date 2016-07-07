class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j = s.size()-1;
        while ( i<=j ) {
            if ( !isalnum(s[i]) ) {i++; continue;}  //Check if character is alphanumeric
            if ( !isalnum(s[j]) ) {j--; continue;}
            if (toupper(s[i]) != toupper(s[j])) {return false;} // Convert lowercase letter to uppercase, also has tolower()
            i++;
            j--; 
        }
        return true;
    }
};