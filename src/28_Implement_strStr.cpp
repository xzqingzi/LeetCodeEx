class Solution {  // Accepted
public:
    int strStr(string haystack, string needle) {
        int out;
        if (!needle.size()) return 0;
        if (haystack.size()<needle.size() ) return -1;
        int j = 0;
        for (int i=0; i<haystack.size()-needle.size()+1; i++) { //No need to iterate i to the end, cause time exceeded as shown below
            int k = i;
            while (j<needle.size()) {
                if (haystack[k++] == needle[j++]) { out = k-j; }  //i is iterated in while loop
                else {j=0; break;}
            }
        }
            if (!j) return -1;
            return out;
    }
};


//The same as above, using i+j instead of k;
class Solution {  // Accepted
public:
    int strStr(string haystack, string needle) {
        int out;
        if (!needle.size()) return 0;
        if (haystack.size()<needle.size() ) return -1;
        int j = 0;
        for (int i=0; i<haystack.size()-needle.size()+1; i++) {
            while (j<needle.size()) {
                if (haystack[i+j] == needle[j]) { out = i; j++;} 
                else {j=0; break;}
            }
        }
            if (!j) return -1;
            return out;
    }
};




class Solution {  // Time limit exceeded
public:
    int strStr(string haystack, string needle) {
        int out;
        if (!needle.size()) return 0;
        if (haystack.size()<needle.size() ) return -1;
        int j = 0;
        for (int i=0; i<haystack.size(); i++) {  
            int k = i;
            while (j<needle.size()) {
                if (haystack[k++] == needle[j++]) { out = k-j; }
                else {j=0; break;}
            }
        }
            if (!j) return -1;
            return out;
    }
};