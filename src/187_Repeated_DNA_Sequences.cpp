//Slow solution 
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> list;
        if (s.size()<=10) return list;
        unordered_set<string> repeat, seen;
        for (int i=0; i<=s.size()-10; i++) {
            string temp = s.substr(i, 10);
            if (seen.count(temp)) repeat.insert(temp);
            else seen.insert(temp);
        }
        for (string n: repeat) {
            list.push_back(n);
        }
        
        return list; 
        
    }
};