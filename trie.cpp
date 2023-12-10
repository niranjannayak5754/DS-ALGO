#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    void addWord(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool searchWord(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node != nullptr && node->isEndOfWord;
    }
};

int main() {
    Trie trie;

    // Add words to the trie
    trie.addWord("hello");
    trie.addWord("world");
    trie.addWord("programming");
    trie.addWord("cplusplus");
    // Search for word
    cout << "Search 'hello': " << (trie.searchWord("hello") ? "Found" : "Not Found") << endl;
    cout << "Search 'world': " << (trie.searchWord("world") ? "Found" : "Not Found") << endl;
    cout << "Search 'python': " << (trie.searchWord("python") ? "Found" : "Not Found") << endl;

    return 0;
}
