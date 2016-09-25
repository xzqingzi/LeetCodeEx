//Much faster solution, use limited size array
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size()==0) return true;
        if (ransomNote.size() > magazine.size()) return false;
        
        int list[26] = {0};  // initialize an array
        for (char temp : magazine) {
            list[temp-'a']++;
        }
        
        for (char temp2 : ransomNote) {
            list[temp2-'a']--;
            if (list[temp2-'a']<0) return false;
        }
        return true;

    }
};




//The same idea, but much slower
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size()==0) return true;
        if (ransomNote.size() > magazine.size()) return false;
        
        unordered_map<char, int> note;
        for (char temp:magazine) {
            if (note.count(temp)) note[temp]++;
            else note[temp] = 1;
        }
        for (int i=0; i<ransomNote.size(); i++) {
            if (!note.count(ransomNote[i])) return false; 
            if (--note[ransomNote[i]] < 0 ) return false;
        }
        return true;

    }
};