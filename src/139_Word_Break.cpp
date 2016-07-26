class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> checklist(s.size()+1, 0);
        checklist[0] = 1;
        for (int i=0; i< s.size(); i++) {
            if (checklist[i]==0) continue;
            for (int j = i; j < s.size()+1; j++) {
                //cout <<i<<"\t"<<j<<"\t"<< s.substr(i,j-i) << endl;
                if(wordDict.find(s.substr(i,j-i)) != wordDict.end()) {
                    checklist[j] = 1;
                }
            }
        }
        if (checklist.back()) return 1;
        return 0;
    }
};


／／Other‘s Solution, faster than above
class Solution {
public:
bool wordBreak(string s, unordered_set<string>& wordDict) {
    if (s.length() < 1){
        return false;
    }
    vector<bool> sub(s.length() + 1);
    sub[0] = true;
    
    for (int i = 0; i < s.length(); i++){
        if (!sub[i]) {continue;}
        for (string word : wordDict){
            int end = i + word.length();
            if(end > s.length() || sub[end]){
                continue;
            }
            if (s.substr(i, word.length())==word){
                sub[end] = true;
            }
        }
    }
    return sub[s.length()];
}
};