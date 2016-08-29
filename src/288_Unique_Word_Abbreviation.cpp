class ValidWordAbbr {
private: 
    unordered_map<string, unordered_set<string>> mymap;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& s: dictionary) {
            int siz = s.size();
            string temp = s[0] + to_string(siz-2) + s[siz-1];
            mymap[temp].insert(s);
        }
    }

    bool isUnique(string word) {
        int siz = word.size();
        string temp = word[0] + to_string(siz-2) + word[siz-1];
        if (!mymap.count(temp)) return 1;
        if (mymap[temp].count(word) == mymap[temp].size()) return 1;
        //if (mymap.count(temp) && (mymap[temp].size() > 1 || !mymap[temp].count(word))) return 0;
        return 0;
    }
};



// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");