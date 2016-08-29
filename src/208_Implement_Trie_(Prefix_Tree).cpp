class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* list[26]; //Use array here, save runtime
    bool isend;
    TrieNode() {
        for(int i=0; i<26; i++) {  // Can use memset to replace for loop and improve the speed
            list[i] = NULL;
        }
        isend = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for (int i=0; i<word.size(); i++) {
            int index = word[i]-'a';
            if (!p->list[index]) {
                p->list[index] = new TrieNode();
            }
            p = p->list[index];
        }
        p->isend = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        for (int i=0; i<word.size(); i++){
            int index = word[i] - 'a';
            if (!p->list[index]) return false;
            p = p->list[index];
        }
        return p->isend;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (int i=0; i<prefix.size(); i++) {
            int index = prefix[i]-'a';
            if (!p->list[index]) return false;
            p = p->list[index];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");