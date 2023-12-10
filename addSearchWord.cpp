/*
    Design a data structure that supports adding new words and finding if a string matches any previously added string.

    Implement the WordDictionary class:
    WordDictionary() Initializes the object.
    void addWord(word) Adds word to the data structure, it can be matched later.
    bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise.
    word may contain dots '.' where dots can be matched with any letter.

*/

#include <bits/stdc++.h>
using namespace std;

class WordDictionary
{
private:
    struct TrieNode
    {
        unordered_map<char, TrieNode *> children;
        bool isWord;

        TrieNode() : isWord(false) {}
    };

    TrieNode *root;

    bool searchHelper(TrieNode *node, const string &word, int index)
    {
        if (index == word.size())
            return node->isWord;

        char curr_ch = word[index];

        if (curr_ch == '.')
        {
            for (const auto &child : node->children)
            {
                if (searchHelper(child.second, word, index + 1))
                    return true;
            }
        }
        else if (node->children.find(curr_ch) != node->children.end())
        {
            return searchHelper(node->children[curr_ch], word, index + 1);
        }

        return false;
    }

public:
    WordDictionary() : root(new TrieNode()) {}

    void addWord(string word)
    {
        TrieNode *node = root;

        for (char ch : word)
        {
            if (node->children.find(ch) == node->children.end())
                node->children[ch] = new TrieNode();
            node = node->children[ch];
        }

        node->isWord = true;
    }

    bool search(string word)
    {
        return searchHelper(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */