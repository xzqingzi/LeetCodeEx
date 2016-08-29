class TrieNode {
private:
    TrieNode* letterMap[26];
    bool isWordAt[26];
public:
    // Initialize your data structure here.
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            letterMap[i] = NULL;
            isWordAt[i] = false;
        }
    }
    TrieNode* getMap(char letter) {
        return letterMap[letter - 'a'];
    }
    TrieNode* newMap(char letter) {
        letterMap[letter - 'a'] = new TrieNode();
        return letterMap[letter - 'a'];
    }
    void setWord(char letter) {
        isWordAt[letter - 'a'] = true;
    }
    bool isWord(char letter) {
        return isWordAt[letter - 'a'];
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* tail = root;
        for (int i = 0; i < word.size() - 1; i++) {
            char letter = word[i];
            if (tail->getMap(letter) != NULL) {
                tail = tail->getMap(letter);
            } else {
                tail = tail->newMap(letter);
            }
        }
        char lastLetter = word[word.size() - 1];
        tail->setWord(lastLetter);
        if (tail->getMap(lastLetter) != NULL) {
            tail = tail->getMap(lastLetter);
        } else {
            tail = tail->newMap(lastLetter);
        }
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* tail = root;
        for (int i = 0; i < word.size() - 1; i++) {
            char letter = word[i];
            if (tail->getMap(letter) != NULL) {
                tail = tail->getMap(letter);
            } else {
                return false;
            }
        }
        char lastLetter = word[word.size() - 1];
        return tail->isWord(lastLetter);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* tail = root;
        for (int i = 0; i < prefix.size(); i++) {
            char letter = prefix[i];
            if (tail->getMap(letter) != NULL) {
                tail = tail->getMap(letter);
            } else {
                return false;
            }
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

