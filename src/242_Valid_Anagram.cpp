class Solution { // all are lowercase alphabets
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return 0; }
        int checklist[26] = {0}; //initialize an array with 26 values of zero
        for (int i=0; i<t.size(); i++) {
            checklist[s[i]-'a'] ++;
            checklist[t[i]-'a'] --;
        }
        for (int i=0; i<26; i++) {
            if (checklist[i]) return 0;
        }
        return 1;
    }
};

class Solution {  // Slower than using array
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return 0; }
        unordered_map<char,int> Mymap; // key and value pair
        for (int i=0; i<s.size(); i++) {
            Mymap[s[i]] ++;
            Mymap[t[i]] --;
        }
        for (auto count: Mymap) {  // WHY?
            if (count.second) return 0; //??
        }
        return 1;
    }
};