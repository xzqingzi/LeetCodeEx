class TrieNode{
public:
    TrieNode* letter[26];
    bool isend;
    TrieNode(){
        for (int i=0; i<26; i++) letter[i] = NULL;
        isend = false;
    }
};

class WordDictionary {
private: 
    TrieNode* root;
    
    bool helper(string& word, int k, TrieNode* p) {
        if (!p) return false;
        if (k == word.size()) return p->isend;
        
        if (word[k] == '.') {
            for (int i=0; i<26; i++) {
                if (p->letter[i]) {
                    if (helper(word, k+1, p->letter[i])) return true;  
                    // can NOT directly return helper, since if helper return false, the loop need to continue to i+1, if directly return helper, the loop will break.
                }
            }
        }
        else if (word[k] != '.') {
            int index = word[k]-'a';
            if (p->letter[index]) return helper(word, k+1, p->letter[index]);
            else return false; 
        }
        return false;
    }
    
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* p = root;
        for (int i=0; i<word.size(); i++) {
            int index = word[i]-'a';
            if (!p->letter[index]) p->letter[index] = new TrieNode();
            p = p->letter[index];
        }
        p->isend = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return helper(word,0,root);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");